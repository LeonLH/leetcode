#include<iostream>
#include<vector>
using namespace std;

// 880ms O(n^2)
class Solution{
public:
	vector<int> countSmaller(vector<int>& nums){
		if(nums.size() == 0){
			vector<int> res;
			return res;
		}
		vector<int> res (nums.size(), 0);
		for(unsigned int i = 0; i < nums.size()-1; ++i)
			for(unsigned int j = i+1; j < nums.size(); ++j)
				if(nums[j] < nums[i])
					res[i]++;
		return res;
	}
};
int main(){
	vector<int> nums = {1}; //{38, 64, 52, 32, 13, 37, 24, 96, 58};
	Solution A;
	vector<int> res = A.countSmaller(nums);

	cout << "The counts vector is:\t";
	for(int i = 0; (unsigned)i < res.size(); ++i)
		cout << res[i] << " ";

	return 0;
}
