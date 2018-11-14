#include<iostream>
#include<vector>
#include<string>
using namespace std;

// dynamic programming. I haven't studied neither. 
class Solution3{
public:
	bool isMatch(string s, string p){
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m+1, vector<bool>(n+1));
		dp[0][0] = true;
		for (int i = 1; i <= m; i++){
			dp[i][0] = false;
		}
		for (int j = 1; j <= n; j++){
			dp[0][j] = p[j-1] == '*' && dp[0][j-2];
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if(p[j-1] != '*')
					dp[i][j] = (p[j-1] == s[i-1] || p[j-1] == '.') && dp[i-1][j-1];
				else
					dp[i][j] = dp[i][j-2] || ((p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j]);

			}
		}
		return dp[m][n];
	}
};

// It works, but I haven't studied yet. 
class Solution2{
public:
	bool isMatch(string s, string p){
		if(p.empty()) 
			return s.empty();
		if('*' == p[1])
			return (isMatch(s, p.substr(2))) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
		else
			return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
	}

};

// have bugs to be solve, in line 71.
class Solution{
private:
	int i = 0, j = 0;
	string str;
	string p;
public:
	bool solve(string &stmp){
		if(stmp == str){
			if((unsigned)i == p.size())
				return true;
			else
				return false;
		}
		else{
			if(p == ".*")
				return true;
			else if(p[i] == str[j]){
				stmp += str[j];
				i++, j++;
				return solve(stmp);
			}
			else if(p[i] == '*'){
				if(i > 0 && (p[i-1] != '.') && (p[i-1] == str[j])){
					if(str[j+1] == str[j]){
						stmp += str[j];				// there is a bug, ex: p:"a*a", str:"aaa"
						j++;
						return solve(stmp);
					}
					else{
						stmp += str[j];
						j++, i++;
						return solve(stmp);
					}
				}
				else if(i > 0 && (p[i-1] == '.')){
					stmp += str[j];
					j++;
					return solve(stmp);
				}
				else if(p[i+1] == str[j]){
					stmp += str[j];
					i += 2;
					j++;
					return solve(stmp);
				}
				else 
					return false;
			}
			else if(p[i] == '.'){
				stmp += str[j];
				i++, j++;
				return solve(stmp);
			}
			else if(p[i] != str[j] && p[i+1] == '*'){
				i += 2;
				return solve(stmp);
			}
			else 
				return false;

			return false;
		}
	}

	bool isMatch(string s, string pattern){
		i = 0, j = 0;
		str = s;
		p = pattern;
		string stmp;
		bool res = solve(stmp);
		return res;
	}

};


int main(){
	string str = "mississippi";//"aab";"ab";//"mississippi";
	string pattern = "mis*is*ip*.";//"c*a*b";//".*c";//"mis*is*ip*."; 
	Solution A;
	bool res = A.isMatch(str, pattern);
	if(res)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
