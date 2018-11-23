#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution{
public:
	static bool comp(int i, int j){
		return i>j;
	}
	int findKthLargest(vector<int> &nums, int k){
		sort(nums.begin(), nums.end(), comp);
		return nums[k-1];
	}
};

int main(){
	vector<int> nums = {3, 2, 1, 5, 6, 4};//{3, 2, 3, 1, 2, 4, 5, 5, 6};//
	Solution A;
	int res = A.findKthLargest(nums, 2);
	cout << res << endl;
	return 0;
}
