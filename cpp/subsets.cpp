#include<iostream>
#include<vector>
using namespace std;
class Solution{
private:
	vector<vector<int>> V;
	vector<int> tmp;
public:
	void helper(vector<int> &nums, int i, int n){
		if(i > n){
			V.push_back(tmp);
		}
		else{
			tmp.push_back(nums[i]);
			helper(nums, i+1, n);
			tmp.erase(tmp.begin()+tmp.size()-1);
			helper(nums, i+1, n);
		}
	}

	vector<vector<int>> subsets(vector<int> &nums){
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
	vector<vector<int>> V = A.subsets(v);
	printVV(V);
	return 0;
}
