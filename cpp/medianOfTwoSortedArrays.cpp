#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
		vector<int>::iterator i1 = nums1.begin();
		vector<int>::iterator i2 = nums2.begin();
		vector<int> res;
		while(i1 != nums1.end()  &&  i2 != nums2.end()){
			if(*i1 <= *i2){
				res.push_back(*i1);
				i1++;
			}
			else{
				res.push_back(*i2);
				i2++;
			}
		}
		if(i1 == nums1.end()){
			for(; i2 != nums2.end(); i2++)
				res.push_back(*i2);
		}
		if(i2 == nums2.end()){
			for(; i1 != nums1.end(); i1++)
				res.push_back(*i1);
		}
		int n = res.size();

		if(n>=2){
			if(n%2)
				return (double)res[n/2];
			else
				return (double)(res[n/2-1]+res[n/2])/2;
		}
		else 
			return res[0];
		
	}
};
int main(){
	vector<int> nums1 = {1, 3, 8, 21, 36, 47};
	vector<int> nums2 = {4, 18, 28, 60};
	vector<int> nums3 = {1, 2};
	vector<int> nums4 = {3, 4};
	Solution A;
	float m = A.findMedianSortedArrays(nums3, nums4);
	return 0;
}
