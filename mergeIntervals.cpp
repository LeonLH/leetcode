#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Interval{
	int start;
	int end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
};

/***************************Solution 8ms****************************/
bool compare(const Interval &a, const Interval &b){
    if(a.start == b.start){
        return a.end < b.end;
    }
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0].start;
        int end = intervals[0].end;
        vector<Interval> ans;
        
        int lastIntervalIndex = 0;
        ans.push_back(intervals[0]);
        for(int i = 1; (unsigned)i < intervals.size(); i++){
            if(intervals[i].start <= end){
                end = max(intervals[i].end, end);
                ans[lastIntervalIndex].end = end;
            }else{
                ans.push_back(intervals[i]);
                lastIntervalIndex++;
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        return ans;
    }
};


//static int x = []() {std::ios_base::sync_with_stdio(false); std::cout.tie(nullptr); return 0; }();
/**********************Solution 160ms*******************************/
class Solution2{
public:
	Interval empty;
	int* flag;
	//merge i and i-1, becuase the ints is sorted, then curr's start is certain bigger than previous's start, don't need to compare it with previous's previous element's end;
	void mergeTwoElement(int &i, vector<Interval> &ints){
		Interval curr;
		curr.start = min(ints[i-1].start, ints[i].start);
		curr.end = max(ints[i-1].end, ints[i].end);
		ints[i] = curr;
		flag[i-1] = 0;
		flag[i] = 1;
	}
	void sortIntervals(vector<Interval> &ints){
		int i = 0;
		int k = ints.size();
		while(k > 0){
			i = 0;
			while(i < k-1){
				int j = i+1;
				if(ints[j].start < ints[i].start){
					Interval tmp = ints[j];
					ints[j] = ints[i];
					ints[i] = tmp;
				}
				++i;
			}
			--k;
		}
	}
	void removeRepeats(vector<Interval> &ints){
		int i = 0;
		vector<Interval> res;
		res.push_back(ints[0]);
		for(i=1; (unsigned)i < ints.size(); ++i){
			if(i == 0)
				continue;
			if(ints[i].start == ints[i-1].start && ints[i].end == ints[i-1].end)
				continue;
			else
				res.push_back(ints[i]);
		}
		ints = res;
	}
	vector<Interval> merge(vector<Interval>& ints){

		if(!ints.size() || ints.size() == 1) return ints;
		flag = new int[ints.size()];
		sortIntervals(ints);
		removeRepeats(ints);
		memset(flag, 0, ints.size() * sizeof(int));
		flag[0] = 1;
		for(int i=0; (unsigned)i < ints.size(); ++i){
			if(i == 0)
				continue;
			flag[i] = 1;
			if(i-1 >= 0 && ints[i].start <= ints[i-1].end){
				mergeTwoElement(i, ints);
			}
		}
		vector<Interval> res;
		for(int i=0; (unsigned)i < ints.size(); ++i){
			if(flag[i])
				res.push_back(ints[i]);
		}
		ints = res;
		return res;
	}
};

/********************Solution 180ms*********************************/
class Solution0{
public:
	Interval empty;
	int* flag;
	int findValidValueBeforeI(int i){
		for(int j=i-1; j>=0; --j){
			if(flag[j])
				return j;
			else
				continue;
		}
		return -1;
	}
	//merge i and valid value before i, then set that value's flag to 0;
	void mergeTwoElement(int &i, int &j, vector<Interval> &ints){
		Interval curr;
		curr.start = min(ints[j].start, ints[i].start);
		curr.end = max(ints[j].end, ints[i].end);
		ints[i] = curr;
		flag[j] = 0;
		flag[i] = 1;
		j = findValidValueBeforeI(j);
	}
	void sortIntervals(vector<Interval> &ints){
		int i = 0;
		int k = ints.size();
		while(k > 0){
			i = 0;
			while(i < k-1){
				int j = i+1;
				if(ints[j].start < ints[i].start){
					Interval tmp = ints[j];
					ints[j] = ints[i];
					ints[i] = tmp;
				}
				++i;
			}
			--k;
		}
	}
	void removeRepeats(vector<Interval> &ints){
		int i = 0;
		vector<Interval> res;
		res.push_back(ints[0]);
		for(i=1; (unsigned)i < ints.size(); ++i){
			if(i == 0)
				continue;
			if(ints[i].start == ints[i-1].start && ints[i].end == ints[i-1].end)
				continue;
			else
				res.push_back(ints[i]);
		}
		ints = res;
	}
	vector<Interval> merge(vector<Interval>& ints){

		if(!ints.size() || ints.size() == 1) return ints;
		flag = new int[ints.size()];
		sortIntervals(ints);
		removeRepeats(ints);
		memset(flag, 0, ints.size() * sizeof(int));
		flag[0] = 1;
		for(int i=0; (unsigned)i < ints.size(); ++i){
			if(i == 0)
				continue;
			flag[i] = 1;
			int j = findValidValueBeforeI(i);
			while(j >= 0 && ints[i].start <= ints[j].end){
				mergeTwoElement(i, j, ints);
			}
		}
		vector<Interval> res;
		for(int i=0; (unsigned)i < ints.size(); ++i){
			if(flag[i])
				res.push_back(ints[i]);
		}
		ints = res;
		return res;
	}
};

/*************************Solution 180ms***************************/
// Solution1 is too slow because the operation remove is very slow to vector. 
class Solution1{
public:
	Interval empty;
	void mergeTwoElement(int &i, vector<Interval> &ints){
		Interval curr;
		curr.start = min(ints[i-1].start, ints[i].start);
		curr.end = max(ints[i-1].end, ints[i].end);
		ints[i] = curr;
		ints.erase(ints.begin()+i-1);
		--i;
	}
	void sortIntervals(vector<Interval> &ints){
		int i = 0;
		int k = ints.size();
		while(k > 0){
			i = 0;
			while(i < k-1){
				int j = i+1;
				if(ints[j].start < ints[i].start){
					Interval tmp = ints[j];
					ints[j] = ints[i];
					ints[i] = tmp;
				}
				++i;
			}
			--k;
		}
	}
	void removeRepeatsAndZero(vector<Interval> &ints){
		int i = 0;

		for(i=1; (unsigned)i < ints.size(); ++i){
			if(i == 0)
				continue;
			if(ints[i].start == ints[i-1].start && ints[i].end == ints[i-1].end){
				ints.erase(ints.begin()+i);
				--i;
			}
		}
	}
	vector<Interval> merge(vector<Interval>& ints){
		if(!ints.size() || ints.size() == 1) return ints;
		sortIntervals(ints);
		removeRepeatsAndZero(ints);
		int curr;
		for(int i=0; (unsigned)i < ints.size(); ++i){
			if(i == 0)
				continue;
			while(i >= 1 && ints[i].start <= ints[i-1].end){
				mergeTwoElement(i, ints);
			}
		}
		return ints;
	}
};
/***************************Utilities*******************************/
void printInterval(vector<Interval> ints){
	cout << "[" ;
	for(int i=0; (unsigned)i < ints.size(); ++i){
		cout << " ";
		cout << "[" << ints[i].start << "," << ints[i].end << "]" ;
		cout << " ";
	}
	cout << "]" ;
}
int main(){
	Interval a0(1, 4);
	Interval a1(0, 4);
	Interval a2(8, 10);
	Interval a3(15, 18);
	vector<Interval> ints;
	ints.push_back(a0);
	ints.push_back(a1);
	ints.push_back(a2);
	ints.push_back(a3);
	cout << "Before sort:\t";
   	printInterval(ints);
	cout << endl;
	Solution A;
//	A.sortIntervals(ints);
//	cout << "After sort:\t";
//   	printInterval(ints);
	cout << endl;
	vector<Interval> emergeRes = A.merge(ints);
	cout << "After emerge:\t";
	printInterval(emergeRes);
	return 0;
}

// Already takes 8H
// Solution1: 6H
// 0. The first step is always producting the input data, e.x. sort, delete zero, illegal check etc. 
// New STEPS:
// 1. Sort the oringnal data with the keyword of start;
// 2. Remove the repeated date in the vector;
// 3. Traverse the vector:
// 		1. Keep maintaining prev and curr element;
// 		2. Compare curr's start and prev's end, if <= , keep emerge() untile curr's start > prev's end;
// 		3. ++i;
// Utilites:
// 		1. emerge(): make curr the same as new element and remove prev in the vector, return vector and curr position(i-1);
//
// Solution2:
// 1. On the basis of above, make every remove operation replaced by mark a flag 1 in an array, and at the end of algorithm, copy the zero elements counterpart to the result vector;
//
// Solution Best:
// 1. Don't after sorted, there's no need to modify the ans's last element's start, all we need to do is modify the end of that element.
