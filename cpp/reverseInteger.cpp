#include<iostream>
#include<climits>
using namespace std;


class Solution{
public:
	int reverse(int x){
		int res = 0;
		while(x){
			if((res == INT_MAX/10 && x > 7) || (res >INT_MAX/10))
				return 0;
			if((res == INT_MIN/10 && x < -8) || (res < INT_MIN/10))
				return 0;
			int tmp = x % 10;
			x /= 10;
			res = res * 10 + tmp;
		}
		return res;
	}
};

int main(){
	int a = -123;
	Solution A;
	cout << a << " becomes ";
	cout << A.reverse(a);
	cout << " after reversed. ";
	return 0;
}
