#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Solution{
private:
	vector<string> resv;
	vector<string> digits;
	string str;

	string d2 = "abc";
	string d3 = "def";
	string d4 = "ghi";
	string d5 = "jkl";
	string d6 = "mno";
	string d7 = "pqrs";
	string d8 = "tuv";
	string d9 = "wxyz";
public:
	void solve(string &str){
		if(str.size() == digits.size()){
			resv.push_back(str);
		}
		else{
			int n = str.size();
			for(unsigned int i = 0; i < digits[n].size(); ++i){
				str += digits[n][i];
				solve(str);
				str.erase(str.begin()+str.size()-1);
			}
		}

	}
	vector<string> letterCombinations(string dgt){
		if(dgt.size() == 0)
			return resv;
		for(unsigned int i = 0; i < dgt.size(); ++i){
			switch (dgt[i]){
				case '2':
					digits.push_back("abc");
					break;
				case '3':
					digits.push_back("def");
					break;
				case '4':
					digits.push_back("ghi");
					break;
				case '5':
					digits.push_back("jkl");
					break;
				case '6':
					digits.push_back("mno");
					break;
				case '7':
					digits.push_back("pqrs");
					break;
				case '8':
					digits.push_back("tuv");
					break;
				case '9':
					digits.push_back("wxyz");
					break;
			}
		}
		solve(str);
		return resv;
	}
};


void printRes(vector<string> res){
	cout << "[\n";
	for(unsigned int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	cout << "]";

}

int main(){
	Solution A;
	string digits = "245";
	vector<string> res = A.letterCombinations(digits);
	printRes(res);
	return 0;
}
