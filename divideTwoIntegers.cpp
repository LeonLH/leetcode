//#29. Divide Two Integers

#include<iostream>
#include<stdlib.h>
using namespace std;
class Solution{
public: 
	int divide(int dividend, int divisor){
		long long int D = dividend;
		long long int S = divisor;
		long long int res = 0;
		long long int abs_divisor = 0;
		int sign = 1;
		if(D < 0){
			sign = 0 - sign;
			D = 0 - D;
		}
		if(S < 0){
			sign = 0 - sign;
			S = 0 - S;
		}
		if(S > D)
			return 0;
		while(S < D)
			S = S << 1;
		if(S > D)
			S = S >> 1;
		// Be careful when substrac of two different size of number.
		if(divisor < 0)
			abs_divisor = 0 - (long long int)divisor;	// Attention!
		else
			abs_divisor = (long long int)divisor;		

		while(S >= abs_divisor){
			if(D >= S){
				D -= S;
				res += 1;
			}
			else if(D < S){
				S >>= 1;
				res <<= 1;
			}
		}
		res >>= 1;
		if(sign < 0)
			res = 0 - res;
		if(res == 2147483648)
			return 2147483647;
		return res;
	}
};
int main(){
	int dividend = -2147483648;
	int divisor = -2147483648;
	Solution A;
	int quotient = A.divide(dividend, divisor);
	cout <<  "\t\t"<< dividend << "/" << divisor << " = " << quotient << endl;
	return 0;
}

