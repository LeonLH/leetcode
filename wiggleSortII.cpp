#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
public:
	// 380ms
	int partition(vector<int>& nums, int low, int high){
		int pivot = nums[low];

		while(low < high){
			while(low < high && nums[high] <= pivot) --high;
			nums[low] = nums[high];
			while(low < high && nums[low] >= pivot) ++low;
			nums[high] = nums[low];
		}
		nums[low] = pivot;
		return low;
	}
	void quickSort(vector<int>& nums, int low, int high){
		if(low < high){
			int pivotpos = partition(nums, low, high);
			quickSort(nums, low, pivotpos-1);
			quickSort(nums, pivotpos+1, high);
		}
		
	}
	// 52ms c++ algorithm's sort is more quick than my quickSort. 
	static bool comp(int i, int j)	{return i>j;}
	void wiggleSort(vector<int>& nums){
		sort(nums.begin(), nums.end(), comp);
		vector<int> res;
		unsigned int n = nums.size()/2;
		unsigned int i = 0;
		while(n < nums.size() || i < nums.size()/2){
			res.push_back(nums[n]);
			++n;
			if(i == nums.size()/2)
				break;
			res.push_back(nums[i]);
			++i;
		}
		nums = res;
	}

};
void printArray(vector<int>& nums){
	for(int i = 0; (unsigned)i < nums.size(); ++i)
		cout << nums[i] << " ";
	cout << endl;
}
int main(){
	vector<int> arr = {4, 5, 5, 5, 5, 6, 6, 6};//{1, 3, 2, 2, 3, 1};//{1, 1, 1, 4, 4, 4, 5, 5, 6}; //{7, 13, 65, 32, 54, 41, 16};
	Solution A;
	A.wiggleSort(arr);
	printArray(arr);

	return 0;
}
/*********************Time Limit Exceeded************************/
class Solution1{
public:
	void bubbleSort(vector<int>& nums){
		int i, j, tmp;
		for(i = 0; (unsigned)i < nums.size(); ++i)
			for(j = nums.size()-1; j > i ; --j)
				if(nums[j] < nums[j-1]){
					tmp = nums[j];
					nums[j] = nums[j-1];
					nums[j-1] = tmp;	
				}
	}
	int findNextBiggerItem(vector<int>& nums, int k){
		for(int i = k; (unsigned)i+1 < nums.size(); ++i){
			if(nums[i+1] > nums[i])
				return i+1;
		}
		return -1;
	}

	void wiggleSort(vector<int>& nums){
		bubbleSort(nums);
		unsigned int i = 1;
		int tmp;
		while(i+1 < nums.size()){
			int k = findNextBiggerItem(nums, i);
			if(k == -1)
				break;
			tmp = nums[k];
			nums[k] = nums[i];
			nums[i] = tmp;
			i += 2;
		}

	}
};
