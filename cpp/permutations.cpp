#include<iostream>
#include<vector>
using namespace std;
// 还可以用两个数组，一个ved存放已经放好了的，一个vun存放未放好的
class Solution{
private:
	vector<vector<int>> V;
public:

	void helper(vector<int> &nums, int start, int end){
		if(start == end){
			V.push_back(nums);
		}
		else{
			for(int i = start; i <= end; ++i){
				swap(nums[i], nums[start]);
				helper(nums, start+1, end);
				swap(nums[i], nums[start]);
			}
		}
	}
	vector<vector<int>> permute(vector<int> &nums){
		helper(nums, 0, nums.size()-1);
		return V;
	}
};

void printVV(vector<vector<int>> &V){
	cout << "[\n";
	for(unsigned int i = 0; i < V.size(); i++){
		cout << "  [";
		for(unsigned int j = 0; j < V[i].size(); j++)
			cout << " " << V[i][j] << " ";
		cout << "]\n";
	}
	cout << "]\n";
}

int main(){
	vector<int> v = {1, 2, 3};
	Solution A;
	vector<vector<int>> V = A.permute(v);
	printVV(V);
	return 0;
}

