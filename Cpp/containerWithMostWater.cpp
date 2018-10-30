#include<vector>
#include<iostream>
using namespace std;
class Solution{
	public:
		int maxArea(vector<int> &height){
			unsigned int i=0, j=0;
			int max=0;
			for(; i<height.size(); ++i){
				for(j=i+1; j<height.size(); ++j){
					int tmp = (j-i)*min(height[i], height[j]);
					if(tmp>max)
						max = tmp;
				}
			}
			return max;
		}
};
int main(){
	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	Solution A;
	int max = A.maxArea(height);
	cout << max << endl;
	return 0;
}
