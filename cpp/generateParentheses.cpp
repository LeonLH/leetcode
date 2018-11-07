#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

class Solution{
	vector<string> resv;
	string str;
	int nleft;
	int nright;
public:
	bool isValid(string &str){
		stack<char> s;
		if(str.size() == 0)
			return true;
		if(str[0] == '(')
			s.push(str[0]);
		else
			return false;
		unsigned int i;
		for(i = 1; i < str.size(); i++){
			if(str[i] == '(')
				s.push(str[i]);
			else if(str[i] == ')'){
				if(!s.empty())
					s.pop();
				else
					return false;
			}
		}
		if(i < str.size())
			return false;
		else 
			return true;
	}
	void solve(string &str){
		if(!nleft && !nright){
			if(isValid(str))
				resv.push_back(str);
		}
		else{
			for(int i = 1; i < 3; ++i){
				if(i == 1 && nleft > 0){
					str += "(";
					nleft--;
					if(isValid(str))
						solve(str);
					string::iterator it = str.end();
					nleft++;
					str.erase(it-1);
				}
				if(i == 2 && nright > 0){
					str += ")";
					nright--;
					if(isValid(str))
						solve(str);
					string::iterator it = str.end();
					nright++;
					str.erase(it-1);
				}
			}
		}
	}

	vector<string> generateParenthesis(int n){
		nleft = n;
		nright = n;
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
	int n = 4;
	Solution A;
	vector<string> res = A.generateParenthesis(n);
	printRes(res);
	return 0;
}
