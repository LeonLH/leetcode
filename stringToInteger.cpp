#include<string>
using namespace std;
class Solution{
public:
	int myAtoi(string str){
		long a = 0;
		//exception check
		for(unsigned int i=0; i<str.size(); ++i){
			if(str[i] == ' ')
				continue;
			else if(str[i] == '-' || str[i] == '+'){
				if(str[i+1] > 57|| str[i+1] < 48)
					return 0;
			}
			else if((str[i]>57 || str[i] < 48)&& str[i]!='-'&& str[i]!='+')
				return 0;
			else
				break;
		}
		int signal = 0;	//init 0, -1 for negative, 1 for positive
		int len = 0;
		for(unsigned int i=0; i<str.size(); ++i){
			if(signal == 0 && str[i] == ' ')
				continue;
			else if(signal == 0 && (str[i]=='-' || str[i] == '+')){
				if(str[i] == '-')
					signal = -1;
				else
					signal = 1;
				continue;
			}
			else if(str[i]>=48 && str[i] <= 57){
				if(!signal)
					signal = 1;
				a = 10*a + (str[i]-48);
				if(a>0)
					++len;
			}
			else if(signal != 0 && (str[i]<48 || str[i]>57))
				break;
		}	
		if(len>10 && signal == 1)
			return 2147483647;	
		if(len>10 && signal == -1)
			return -2147483648;
		if(signal == 0)
			return 0;
		if(signal == -1)
			a = -1 * a;
		if(a>2147483647)
			return 2147483647;
		else if(a<-2147483648)
			return -2147483648;
		else
			return (int)a;
	}
};
int main(){
	Solution A;
	string s = "4193 with words";
	int s1 = A.myAtoi(s);
	return 0;
}
