#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		if(nums.size() == 0) return 0;
		unsigned int i=1;
		int len=1;
		while(i<nums.size()){
			if(nums[i]>nums[i-1]){
				nums[len] = nums[i];
				++len;
			}
			++i;
		}
		return len;
	}
};
int main(){
	vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	Solution A;
	unsigned int len = A.removeDuplicates(nums);
	for(unsigned int i=0; i<len; ++i){
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}
