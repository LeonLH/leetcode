#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:
	int search(vector<int>& nums, int target){
		if(nums.size()==0) return -1;
		int begin=0, end=0 ;
		end = nums.size()-1;
		
		while(begin<=end){
			int mid =(begin+end)/2;
			if(nums[mid] == target)
				return mid;
			if(target >= nums[begin]){			//first half branch
				if(nums[mid] >= nums[begin]){	//long before short after
					if(target <= nums[mid])
						end = mid;
					else
						begin = mid+1;			//mid+1 is very important, It can make sure begin moving forward.
				}
				else							//short before long after
					end = mid;
			}
			else{								//last half branch
				if(nums[mid] > nums[end])		//long before short after
					begin = mid+1;				//`begin = mid+1` is important, otherwise is will not come out of loop, and the other important 
												//thing is that > is conpany with +1, < is company with -1;
				else{							//short before long after
					if(target < nums[mid])
						end = mid-1;			//mid-1 is important too.
					else
						begin = mid;
				}
			}
		}
		return -1;
	}
};
int main(){
	vector<int> nums = {3, 1};//{4, 5, 6, 7, 0, 1, 2};
	int target = 1;
	Solution A;
	int idx = A.search(nums, target);
	cout << idx << endl;
	cin.get();
	return 0;

}
