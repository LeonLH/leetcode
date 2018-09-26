#include<iostream>
#include<string.h>
#include<string>
using namespace std;
//有两种可能，第一种是以本字符对称，第二种是以字符之间的空隙为对称轴，设置一个数组，数组内存放回文的长度；
//注意：每次判断时，判断完第一种情况，还要判断第二种情况，因为有可能既以字符对称，又以空隙对称，要以他们的最大值存入数组中。
class Solution{
public:
	string longestPalindrome(string s){
		if(!s.size())
		{
			string stmp = "";
			return stmp;
		}
		int ss[1002]={0};
		int n = s.size();
		for(int i=0; i<n; ++i)
			ss[i] = 1;
		int i = 0;
		int tmp;
		while(i<n){
			int j = 1;
			int tmp1=0, tmp2=1;
			if((i-j+1>=0) && (s[i-j+1] == s[i+j])&& (i+j<=n-1)){
				tmp1 = 0;
				while((i-j+1>=0) && (s[i-j+1] == s[i+j])&& (i+j<=n-1))
					++j;
				tmp1 += 2*j-2;
			}
			j = 1;
			if((i-j>=0) && (s[i-j] == s[i+j]) && (i+j<=n-1)){
				tmp2 = 1;
				while((i-j>=0) && (s[i-j] == s[i+j]) && (i+j<=n-1))
					++j;
				tmp2 += 2*j-2;
			}
			ss[i] = ((tmp1>tmp2)? tmp1:tmp2);
			++i;
		}
		int max_index=0;
		i = 0;
		while(ss[i]>=1 && i<1000){
			if(ss[i]>ss[max_index])
				max_index = i;
			++i;
		}
		int max = ss[max_index];
		string res;
		if(max%2){
			string res(s, max_index-max/2, max);
			return res;
		}
		else{
			string res(s, max_index-max/2+1, max);
			return res;
		}
	}
};
int main(){
	string s = "aaaaaaaa";
	Solution A;
	string res = A.longestPalindrome(s);
	return 0;
}
