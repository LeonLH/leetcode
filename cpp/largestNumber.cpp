#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
public:
	static bool comp(string s1, string s2){
		if(s1 + s2 > s2 + s1)
			return true;
		else
			return false;
	}
	string largestNumber(vector<int>& nums){
		int k;
		for(k = 0; (unsigned)k < nums.size(); ++k){
			if(nums[k] != 0)
				break;
		}
		if((unsigned)k == nums.size()){
			return to_string(0);
		}

		vector<string> strnums;
		for(int i = 0; (unsigned)i < nums.size(); ++i)
			strnums.push_back(to_string(nums[i]));
		int i, j;
		string tmp;
		for(i = 1; (unsigned)i < strnums.size(); ++i){
			tmp = strnums[i];
			for(j = i-1; j >= 0 && comp(tmp, strnums[j]); --j)
				strnums[j+1] = strnums[j];
			strnums[j+1] = tmp;
		}
		string res;
		for(i = 0; (unsigned)i < strnums.size(); ++i)
			res += strnums[i];
		
		return res;

	}
};
int main(){
	vector<int> vec = {121, 12}; //{3, 30, 34, 5, 9};
	Solution A;
	string str = A.largestNumber(vec);
	cout << "The result is:\t" << str ;
	return 0;
}

/* History, cannot catch goal. 
// 0. compare the first number return the bigger one, if equal, 
// 	compare the seconde number.
// 1. Sort insertSort(The type of sort can be any one). 
// 2. Output to a string. 
// 3. The key is compare function. 
class Solution1{
public:
	int astep = 0, bstep = 0;
	int afirst , bfirst;
	bool compare(int a, int b){
		if(a == b)
			return true;
		if(a == 0 && b != 0){
			if(afirst < b)
				return false;
			else
				return true;
		}
		if(a != 0 && b == 0){
			if(bfirst < a)
				return true;
			else
				return false;
		}
		int ahead = a, bhead = b;
		while(ahead/10){
			ahead /= 10;
			astep++;
		}
		while(bhead/10){
			bhead /= 10;
			bstep++;
		}
		if(ahead > bhead)
			return true;
		else if(ahead < bhead)
			return false;
		else{
			if((a-ahead * pow(10, astep)) == 0  && (b - bhead * pow(10, bstep)) == 0)
				return compare(bstep, astep);
			else
				return compare(a-ahead * pow(10, astep), b - bhead * pow(10, bstep));
		}
	}	// compare 121 with 12, 12 should be bigger than 121. Think about this.
	void getFirst(int a, int b){
		
		while(a/10)
			a /= 10;
		afirst = a;
		while(b/10)
			b /= 10;
		bfirst = b;

	}
	static bool compare1(string& s1, string &s2){
		if(s1 + s2 > s2 +s1)
			return true;
		else
			return false;
	}
	string largestNumber(vector<int>& nums){
		int i, j, tmp;
		int n = nums.size();
		for(i = 1; i < n; ++i){
			tmp = nums[i];
			for(j = i-1; j >= 0 && compare1(tmp, nums[j]); --j){
				nums[j+1] = nums[j];
			}
			nums[j+1] = tmp;
		}
		string res;
		for(int i = 0; (unsigned)i < nums.size(); ++i){
			stringstream ss;
			ss << nums[i];
			res += ss.str();
		}
		return res;
	}
};
*/
