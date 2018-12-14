// unsolved 
#include<vector>
#include<iostream>
using namespace std;

struct buildings{
	int L;
	int R;
	int H;
};

// Method 2: brute force, time comlexity: all the buildings pixels, 
// it's very large. 
// 1. Draw/init a blank area.
// 2. Draw each build in the area
// 3. Statistic each line of the area, if it differ from previous then
// add this line to result vector. 
//
// Method 1:
// This problem may be complicated using c++, It may be easier with 
// python or octave language. 
// 1. first from left to right to get the left edge of skyline
// 2. from right to left to get the right edge of skkyline
// 3. sort the pair of results by the first element(x coordinates)
class Solution{
	
public:

	void sortBuildingsByRightEdge(vector<struct buildings> &B){
		
	}

	vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings){
		vector<pair<int, int>> res;
		int n = buildings.size();

		vector<struct buildings> B;
		for(int i = 0; i < n; i++){
			struct buildings tmp;
			tmp.L = buildings[i][0];
			tmp.R = buildings[i][1];
			tmp.H = buildings[i][2];
			B.push_back(tmp);
		}

		pair<int, int> tmp;
		tmp = make_pair(B[0].L, B[0].H);
		res.push_back(tmp);

		// From left to right, get the increase skyline
		for(int i = 1; i < n; i++){
			if(B[i].L > B[i-1].R){		// seperated
				// find the i-1 buildings rightest position pos
				// tmp = make_pair(pos, 0);
				// res.push_back(tmp);
				tmp = make_pair(B[i].L, B[i].H);
				res.push_back(tmp);
			}
			// overlaped 
			else if(B[i].H >  B[i-1].H){
				tmp = make_pair(B[i].L, B[i].H);
				res.push_back(tmp);
			}
			else if(B[i].H == B[i-1].H){
				continue;	// just skep and process next buildings.
			}
			else if(B[i].H <  B[i-1].H){
				// The height of current line could be determined by 
				// previous buildings, which right edge is beyond the
				// i-1 building's right edge. 
				continue; 	// remain to let next step to process. 
			}
		}
		
		sortBuildingsByRightEdge(B);
		// From right to left, get the decrease skyline
		for(int i = n-1; i >= 0; i--){
			
		}
		return res;
	}
};

// Initialize area with '#'
void initArea(vector<vector<char>> &area){
	for(int i = 0; (unsigned)i < area.size(); i++)
		for(int j = 0; (unsigned)j < area[0].size(); j++){
			area[i][j] = '#';
		}
}

void printBuilding(vector<vector<char>> area){
	cout << endl;
	for(int i = area.size()-1; i >= 0; i--){
		for(int j = 0; (unsigned)j < area[0].size(); j++){
			cout << area[i][j];
		}
		cout << endl;
	}
	for(int j = 0; (unsigned)j < area[0].size(); j++){
		cout << '=' ;
	}
	cout << endl;
}

void makeBuildingToArea(vector<int> b1, vector<vector<char>> &area){
	for(int i = 0; i < b1[2]; i++)
		for(int j = b1[0]-1; j < b1[1]; j++)
			area[i][j] = ' ';
}

int main(){
	vector<int> b1 = {2, 9, 10};
	vector<int> b2 = {3, 7, 15};
	vector<int> b3 = {5, 12, 12};
	vector<int> b4 = {15, 20, 10};
	vector<int> b5 = {19, 24, 8};
	vector<vector<int>> buildings;
	buildings.push_back(b1);
	buildings.push_back(b2);
	buildings.push_back(b3);
	buildings.push_back(b4);
	buildings.push_back(b5);

	vector<vector<char>> area;
	vector<char> areaMakeTmp;
	areaMakeTmp.resize(50);
	int areaHeight = 20;
	for(int i = 1; i <= 20; i++)
		area.push_back(areaMakeTmp);
	initArea(area);
	makeBuildingToArea(b1, area);
	makeBuildingToArea(b2, area);
	makeBuildingToArea(b3, area);
	makeBuildingToArea(b4, area);
	makeBuildingToArea(b5, area);
	printBuilding(area);

	Solution A;
	vector<pair<int, int>> res = A.getSkyline(buildings);
	return 0;
}
