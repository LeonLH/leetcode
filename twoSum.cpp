#include <vector>
#include <iostream>
using namespace std;
class Solution1{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unsigned int i = 0,j = 0;
		vector<int> res(2);
		while(i<nums.size())	//i一共size此循环，从头到尾
		{
			j = i+1;
			while(j<nums.size())	//每一个小循环中，j从i+1循环到尾部
			{
				if( nums[j] + nums[i] == target )
				{
					res[0] = i;
					res[1] = j;
					break;
				}					
				++j;
			}
			++i;
		}
		return res;
    }
};
class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		int nlen = nums.size();
		int i = 0,j = 0;
		vector<int> res(2);
		for(i=0;i<nlen;++i){
			for(j=i+1;j<nlen;++j){
				if(nums[i]+nums[j] == target){
					res[0] = i;
					res[1] = j;
					return res;
				}
			}			
		}

	cout << "Not found"<<endl;	
	res = {0,0};
	return res;
	}
	
};

int main(){
	int test1[] = {2, 7, 11, 15};
	vector<int> nums(test1, test1+4);
	int target = 9;
	Solution A;
	vector<int> res = A.twoSum(nums, target);
	cout << res[0] << res[1] <<endl;	
	return 0;

}
