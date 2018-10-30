#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
// 12ms Using an array to store the frequency of every char. 
class Solution{
public:
	bool isAnagram(string s, string t){
		int iS[128] = {0};
		int iT[128] = {0};
		int iLenS = s.size();
		int iLenT = t.size();
		if(iLenS != iLenT)
			return false;
		for(int i=0; i < iLenS; ++i){
			iS[(int)s[i]]++;
			iT[(int)t[i]]++;
		}
		for(int i=0; i < iLenS; ++i){
			if(iS[(int)s[i]] != iT[(int)s[i]])
				return false;
		}
		return true;
	}
};

// 20ms
class Solution1{
public:
	static bool comp(char a, char b) {return a < b;}
	bool isAnagram(string s, string t){
		sort(s.begin(), s.end(), comp);
		sort(t.begin(), t.end(), comp);
		if(s == t)
			return true;
		else
			return false;
	}
};
int main(){
	string s = "anagram";
	string t = "nagaram";
	Solution A;

	bool x = A.isAnagram(s, t);
	if(x)
		cout << "Yes!";
	else
		cout << "No!";
	return 0;
}
