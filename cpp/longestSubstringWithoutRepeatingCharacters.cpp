#include<iostream>
#include<string>
#include<string.h>
using namespace std;
//also can use a unorder map
//using hash table
class Solution1{
public:
	bool isExist(int c, unsigned int j, int* hash, unsigned int& sub){
		if(hash[c] != -1){
			sub = hash[c];
			return true;
		}
		else{
			hash[c] = j;
			return false;
		}
	}
	int lengthOfLongestSubstring(string s){
		int hash[256] ;
		memset(hash, -1, sizeof(hash));
		if(!s.size()) return 0;
		int tmp = 0;
		int max = 0;
		unsigned int sub = 0;

		hash[(int)s[0]] = 0 ;
		sub = 0;
		for(unsigned int i=0; i<s.size(); ++i){

			tmp = 1;
			for(unsigned int j = i+1; j<s.size(); ++j){
				if(isExist((s[j]), j, hash, sub)){
					i = sub;
					break;
				}
				else{
					++tmp;
				}

			}
			if(tmp>max)
				max = tmp;
		}
		return max;
	}
};
//Right answer but slow, use hash can speed up
class Solution2{
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
		unsigned int i=0, j=1;
		unsigned int nlen = 0;
		unsigned int sub = 0;
		unsigned int n = s.length();
		while(i<n){
			if(n-i < max)
				break;
			nlen = j-i;
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
			++j;
			if(nlen>max)
				max = nlen;
			++i;
		}
		return max;
	}
};
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
		unsigned int nlen = 0;
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
	string s = "dvdf";
	int a;
	Solution2 A;
	int len = A.lengthOfLongestSubstring(s);
	cout << len << endl;
	cin.get();
	return 0;
}
