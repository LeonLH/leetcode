#include<string>
#include<iostream>
#include<list>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.size();
		int listSize = 2 * numRows - 2; // numRows > 1
		int listIt = 0;
		list<char> lit;
		vector<list<char>> retVec;

		for(string::iterator it = s.begin(); it != s.end(); ++it){
			if(listIt == listSize){
				retVec.push_back(lit);
				lit.clear();
				listIt = 0;
			}
			char c = *it;
			lit.push_back(c);
			listIt++;
		}





		return s;
	}
};

int main(){
	string str = "PAYPALISHIRING";
	Solution A;
	string strRet = A.convert(str, 3);
	cout << "strRet: " << strRet << endl;
	return 0;
}
