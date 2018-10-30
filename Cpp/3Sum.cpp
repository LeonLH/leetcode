#include<vector> 
#include<algorithm>
using namespace std;
class Solution1{
	public:
		vector<vector<int>> threeSum(vector<int>& nums){
			if(nums.size()<=2) return {};
			vector<vector<int>> resVec;
			unsigned int i=0, j=0, k=0;
			for(; i<nums.size()-2; ++i){
				for(j=i+1; j<nums.size()-1; ++j){
					for(k=j+1; k<nums.size(); ++k){
						if(nums[i]+nums[j]+nums[k] == 0){
							vector<int> tmp = {nums[i], nums[j], nums[k]};
							sort(tmp.begin(), tmp.end());
							unsigned int l = 0;
							for(l=0; l<resVec.size(); ++l)
								if(resVec[l] == tmp)
									break;
							if(l == resVec.size())
								resVec.push_back(tmp);
						}
						
					}
				}
			}
			return resVec;
		}
};
class Solution{
	public:
		vector<vector<int>> threeSum(vector<int>& nums){
			if(nums.size()<=2) return {};
			sort(nums.begin(), nums.end());
			vector<vector<int>> resVec;
			unsigned int i=0, start=0, end=0;
			end = nums.size()-1;
			while(i<nums.size()-2){
				start = i+1;
				end = nums.size()-1;
				while(start<end){
					if(nums[i]+nums[start]+nums[end]>0){
						--end;
						while((start<end)&&(nums[end] == nums[end+1])) --end;
					}
					else if(nums[i]+nums[start]+nums[end]<0){
						++start;
						while((start<end)&&(nums[start] == nums[start-1])) ++start;
					}
					else{
						resVec.push_back({nums[i], nums[start], nums[end]});
						++start;
						while((start<end)&&(nums[start] == nums[start-1])) ++start;
					}
				}
				++i;
				while((i<nums.size()-2)&&(nums[i] == nums[i-1])) ++i;
			}
			return resVec;
		}
};
int main(){
	vector<int> nums= {-1, 0, 1, 2, -1, -4};
	Solution A;
	vector<vector<int>> resVec = A.threeSum(nums);
	return 0;
}
