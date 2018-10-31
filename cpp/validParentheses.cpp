#include<iostream>
#include<string>
#include<stack>

using namespace std;
class Solution{
public:
	bool isMatch(char c1, char c2){
		switch (c1){
			case '(':{
						 if(c2 == ')')
							 return true;
						 else
							 return false;
					 }
			case '[':{
						 if(c2 == ']')
							 return true;
						 else
							 return false;
					 }
			case '{':{
						 if(c2 == '}')
							 return true;
						 else
							 return false;
					 }

		}
		return false;
	}
	bool isValid(string s){
		if(s.empty()) return true;
		stack<char> st;
		for(string::iterator it = s.begin(); it!=s.end(); ++it){
			if(st.empty())
				st.push(*it);
			else{
				char c = st.top();
				if(isMatch(c, *it))
					st.pop();
				else
					st.push(*it);
			}
		}
		return st.empty();
	}
};
int main(){
	string s = "{[()]}";
	Solution A;
	int i = 0;
	i = A.isValid(s);
	cin.get();
	return 0;
}
