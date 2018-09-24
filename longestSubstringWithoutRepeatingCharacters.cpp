#include<iostream>
#include<string>
using namespace std;
//time limit exceeded solution:
class Solution{
public:
	bool isExist(char c, string s, unsigned int i, unsigned int j, unsigned int& sub){
		for(unsigned int it = i; it<=j; ++it){
			if(s[it] == c){
				sub = it;
				return true;
			}
		}
		return false;
	}
	int lengthOfLongestSubstring(string s){
		if(!s.size()) return 0;
		unsigned int max=0, tmp=0;
		unsigned int i=0, j=0;
		 int nlen = 0;
		unsigned int sub = 0;
		unsigned int n = s.length();
		while(i<n){
			if(n-i < max)
				break;
			j = i+1;
			nlen = 1;
			while(j<n){
				if(!isExist(s[j], s, i, j-1, sub)){
					++j;
					++nlen;
				}
				else{
					i = sub;
					break;
				}
			}
			if(nlen>max)
				max = nlen;
			++i;
		}
		return max;
	}
};
int main(){
	string s = "bcabcbb";
	Solution A;
	int len = A.lengthOfLongestSubstring(s);
	cout << len << endl;
	cin.get();
	return 0;
}
