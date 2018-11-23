#include<vector>
#include<limits.h>
#include<iostream>
#include<algorithm>
using namespace std;

// Solution from submission Distribution. Time complexity O(n).
class Solution{
public:
	// If nums[i] equals to ans, count++, otherwise count--
	int majorityElement(vector<int> &nums){
		int count = 0;
		int ans;
		for(int num: nums){
			if(count == 0)
				ans = num;
			if(num == ans)
				count++;
			else
				count--;
		}
		return ans;
	}
};

// time complexity O(nlogn)
class Solution1{
public:
	int majorityElement(vector<int> &nums){
		if(nums.size() == 1)
			return nums[0];
		sort(nums.begin(), nums.end());
		int idx = nums.size()/2;
		return nums[idx];
	}
};

int main(){
	vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
	Solution A;
	int res = A.majorityElement(nums);
	cout << res << endl;
	return 0;
}
