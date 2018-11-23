#include<limits.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

// 8ms, solution from submission distribution.  
// If sum is negative, make it 0, because the sum of negative and any
// other number will make that number smaller.  
class Solution{
public:
	int maxSubArray(vector<int> &nums){
		int sum = 0;
		int ans = INT_MIN;
		for(int i = 0; i < (int)nums.size(); i++){
			sum += nums[i];
			ans = max(sum, ans);
			sum = max(sum,   0);
		}
		return ans;
	}
};


// On the basis of above algorithm, this problem can be implemented 
// with the idea of Divide and Conquer.

class Solution3{
public:
	int maxSubArrayHelper(int l, int r, vector<int>& nums){
		if(l > r)
			return INT_MIN;
		int m = (l + r)/2;

		int lmax = 0;
		int sum = 0;
		for(int i = m-1; i >= l; --i){
			sum += nums[i];
			lmax = max(lmax, sum);
		}

		int rmax = 0;
		sum = 0;
		for(int i = m+1; i <= r; ++i){
			sum += nums[i];
			rmax = max(rmax, sum);
		}

		int lAns = maxSubArrayHelper(l, m-1, nums);
		int rAns = maxSubArrayHelper(m+1, r, nums);

		return max(lmax + nums[m] + rmax, max(lAns, rAns));
	}

	int maxSubArray(vector<int>& nums){
		int n = nums.size();
		return maxSubArrayHelper(0, n-1, nums);
	}
};


// Dynamic programming with some simplify, update max to avoid store
// the status of each subarray.
// Accepted, 140ms, time complexity O(n^2).
class Solution2{
public:
	int maxSubArray(vector<int> &nums){
		int max = nums[0];
		int n = nums.size();
		for(int i = 0; i < n; i++){
			int j = i;
			int tmp = nums[i];
			max = max > tmp ? max : tmp;	// didn't get in the loop
			for(j = i+1; j < n; j++){
				tmp += nums[j];
				max = max > tmp ? max : tmp;	
			}	
			if(i+1 >= n)
				break;
			tmp -= nums[i];
			max = max > tmp ? max : tmp;	
			i++;
			for(j = n-1; j > i; j--){
				tmp -= nums[j];
				max = max > tmp ? max : tmp;	
			}
		}
		return max;
	}
};

// Unaccepted. Brute force: Time limit exceeding 
// 1^2 + 2^2 + 3^2 +...+ n^2 time complexity : O(n3)
class Solution1{
public:
	int maxSubArray(vector<int>& nums){
		// bounds checking if nums.size() == 0
		int n = nums.size();
		int min = nums[0];
		for(int i = 0; i < n; i++){
			if(nums[i] < min)
				min = nums[i];
		}
		int max = min;

		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				int tmp = nums[i];
				for(int k = i+1; k <= j; ++k)
					tmp += nums[k];
				if(tmp > max)
					max = tmp;
			}

			if(nums[i] > max)
				max = nums[i];
		}
		return max;
	}

};

int main(){
	vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};//{-1, 1, 2, 1};//{-3, -2, 0, -1};//
	Solution A;
	int res = A.maxSubArray(v);
	cout << "The sum of largest subarray is " << res << endl;
	return 0;
}
