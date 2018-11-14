#include<iostream>
#include<string>
#include<vector>
using namespace std;

// maybe backtracking isn't way to this problem. 
class Solution{
private:
	vector<string> resv;
	vector<string> dict;
	string stmp;
public:

	vector<string> availableStr(string& left){
		vector<string> res;
		for(unsigned int i = 0; i < dict.size(); i++){
			if(left.substr(0, dict[i].size()) == dict[i])
				res.push_back(dict[i]);
		}
		return res;
	}

	void solve(string& left){
		if(left.size() == 0)
			resv.push_back(stmp);
		else{
			vector<string> children = availableStr(left);
			for(int i = 0; (unsigned)i < children.size(); i++){
				string str = children[i];
				stmp += " ";
				stmp += str;
				left = left.substr(str.size());
				solve(left);
				left = str + left;
				stmp = stmp.substr(0, stmp.size()-str.size()-1);
			}
		}
	}

	bool haveCharInDict(string& str){
		for(unsigned int i = 0; i < str.size(); i++)
			for(unsigned int j = 0; j < dict.size(); j++)
				for(unsigned int k = 0; k < dict[j].size(); k++)
					if(str[i] == dict[j][k])
						return true;
		return false;

	}
	vector<string> wordBreak(string s, vector<string>& wordDict){
		string left = s;
		dict = wordDict;
		if(!haveCharInDict(left))
			return resv;
		solve(left);
		for(unsigned int i = 0; i < resv.size(); i++)
			resv[i] = resv[i].substr(1);
		return resv;
	}
};


void printRes(vector<string> res){
	cout << "[\n";
	for(int i = 0; (unsigned)i < res.size(); i++){
		cout << "  " << res[i] << endl;
	}
	cout << "]\n";
}

int main(){
	string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	vector<string> wordDict1 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	string s = "pineapplepenapple";
	vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
	Solution A;
	vector<string> res = A.wordBreak(s1, wordDict1);
	printRes(res);
	return 0;
}
