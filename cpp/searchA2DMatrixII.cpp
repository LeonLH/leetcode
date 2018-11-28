#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target){
		if(matrix.empty())
			return false;
		int col = matrix[0].size();
		int row = matrix.size();
		int i = 0;
		int j = col-1;
		while(i < row && j >= 0){
			if(target == matrix[i][j])
				return true;
			else if(target > matrix[i][j]){
				i++;
			}
			else if(target < matrix[i][j]){
				j--;
			}
			
		}
		return false;
	}
};

int main(){
	vector<vector<int>> matrix;
	vector<int> v1 = {1,  4,  7,  11, 15};
	vector<int> v2 = {2,  5,  8,  12, 19};
	vector<int> v3 = {3,  6,  9,  16, 22};
	vector<int> v4 = {10, 13, 14, 17, 24};
	vector<int> v5 = {18, 21, 23, 26, 30};
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
	matrix.push_back(v5);
	Solution A;
	bool res = A.searchMatrix(matrix, 5);
	if(res)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	res = A.searchMatrix(matrix, 20);
	if(res)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}
