#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// There is better way like yesterday's anagram problem: the map way. The following is code:
// 4ms
class Solution1{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
		vector<int> res;
		map<int, int> mymap;
		for(int i = 0; (unsigned)i < nums1.size(); i++)
			mymap[nums1[i]]++;
		for(int i = 0; (unsigned)i < nums2.size(); ++i){
			if(mymap[nums2[i]] > 0){
				mymap[nums2[i]]--;
				res.push_back(nums2[i]);
			}
		}
		return res;
};
// 4ms
class Solution{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
		vector<int> res;
		if(!nums1.size() || !nums2.size())
			return res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();
		do{
			if(*it1 == *it2){
				res.push_back(*it1);
				++it1;
				++it2;
			}
			else if(*it1 < *it2)
				++it1;
			else
				++it2;
		}while(it1 != nums1.end() && it2 != nums2.end());
		return res;
	}
};
int main(){
	vector<int> nums1 = {15, 18, 26, 13, 5, 9};
	vector<int> nums2 = {18, 5, 5, 13, 92, 36};
	Solution A;
	vector<int> res = A.intersect(nums1, nums2);
	return 0;
}
