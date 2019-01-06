#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
	int numberOfHund(string Hund){
		int num = 0;
		if(Hund == "C")
			num = 1;
		else if(Hund == "CC")
			num = 2;
		else if(Hund == "CCC")
			num = 3;
		else if(Hund == "CD")
			num = 4;
		else if(Hund == "D")
			num = 5;
		else if(Hund == "DC")
			num = 6;
		else if(Hund == "DCC")
			num = 7;
		else if(Hund == "DCCC")
			num = 8;
		else if(Hund == "CM")
			num = 9;
		else
			num = 0;
		return num;
	}
	int numberOfDeci(string Deci){
		int num = 0;
		if(Deci == "X")
			num = 1;
		else if(Deci == "XX")
			num = 2;
		else if(Deci == "XXX")
			num = 3;
		else if(Deci == "XL")
			num = 4;
		else if(Deci == "L")
			num = 5;
		else if(Deci == "LX")
			num = 6;
		else if(Deci == "LXX")
			num = 7;
		else if(Deci == "LXXX")
			num = 8;
		else if(Deci == "XC")
			num = 9;
		else 
			num = 0;
		return num;
	}
	int numberOfOnes(string Ones){
		int num = 0;
		if(Ones == "I")
			num = 1;
		else if(Ones == "II")
			num = 2;
		else if(Ones == "III")
			num = 3;
		else if(Ones == "IV")
			num = 4;
		else if(Ones == "V")
			num = 5;
		else if(Ones == "VI")
			num = 6;
		else if(Ones == "VII")
			num = 7;
		else if(Ones == "VIII")
			num = 8;
		else if(Ones == "IX")
			num = 9;
		else
			num = 0;
		return num;
	}

	int procThou(string& s){
		if(s.substr(0, 3) == "MMM"){
			s = s.substr(3);
			return 3;
		}
		else if(s.substr(0, 2) == "MM"){
			s = s.substr(2);
			return 2;
		}
		else if(s.substr(0, 1) == "M"){
			s = s.substr(1);
			return 1;
		}
		else 
			return 0;
	}	
	int procHund(string& s){
		if(s.substr(0, 3) == "CCC"){
			s = s.substr(3);
			return 3;
		}	
		else if(s.substr(0, 2) == "CC"){
			s = s.substr(2);
			return 2;
		}	
		else if(s.substr(0, 2) == "CD"){
			s = s.substr(2);
			return 4;
		}	
		else if(s.substr(0, 2) == "CM"){
			s = s.substr(2);
			return 9;
		}	
		else if(s.substr(0, 1) == "C"){
			s = s.substr(1);
			return 1;
		}	
		else if(s.substr(0, 4) == "DCCC"){
			s = s.substr(4);
			return 8;
		}	
		else if(s.substr(0, 3) == "DCC"){
			s = s.substr(3);
			return 7;
		}	
		else if(s.substr(0, 2) == "DC"){
			s = s.substr(2);
			return 6;
		}	
		else if(s.substr(0, 1) == "D"){
			s = s.substr(1);
			return 5;
		}	
		else 
			return 0;
	}	

	int procDeci(string& s){
		if(s.substr(0, 3) == "XXX"){
			s = s.substr(3);
			return 3;
		}	
		else if(s.substr(0, 2) == "XX"){
			s = s.substr(2);
			return 2;
		}	
		else if(s.substr(0, 2) == "XL"){
			s = s.substr(2);
			return 4;
		}	
		else if(s.substr(0, 2) == "XC"){
			s = s.substr(2);
			return 9;
		}	
		else if(s.substr(0, 1) == "X"){
			s = s.substr(1);
			return 1;
		}	
		else if(s.substr(0, 4) == "LXXX"){
			s = s.substr(4);
			return 8;
		}	
		else if(s.substr(0, 3) == "LXX"){
			s = s.substr(3);
			return 7;
		}	
		else if(s.substr(0, 2) == "LX"){
			s = s.substr(2);
			return 6;
		}	
		else if(s.substr(0, 1) == "L"){
			s = s.substr(1);
			return 5;
		}	
		else 
			return 0;
	}	
	int procOnes(string& s){
		if(s.substr(0, 3) == "III"){
			s = s.substr(3);
			return 3;
		}	
		else if(s.substr(0, 2) == "II"){
			s = s.substr(2);
			return 2;
		}	
		else if(s.substr(0, 2) == "IV"){
			s = s.substr(2);
			return 4;
		}	
		else if(s.substr(0, 2) == "IX"){
			s = s.substr(2);
			return 9;
		}	
		else if(s.substr(0, 1) == "I"){
			s = s.substr(1);
			return 1;
		}	
		else if(s.substr(0, 4) == "VIII"){
			s = s.substr(4);
			return 8;
		}	
		else if(s.substr(0, 3) == "VII"){
			s = s.substr(3);
			return 7;
		}	
		else if(s.substr(0, 2) == "VI"){
			s = s.substr(2);
			return 6;
		}	
		else if(s.substr(0, 1) == "V"){
			s = s.substr(1);
			return 5;
		}	
		else 
			return 0;
	}	


	int romanToInt(string s){
		int thou = 0;
		int hund = 0;
		int deci = 0;
		int ones = 0;

		while(s.size()){
			if(s[0] == 'M')
				thou = procThou(s);
			else if(s[0] == 'C' || s[0] == 'D')
				hund = procHund(s);
			else if(s[0] == 'X' || s[0] == 'L')
				deci = procDeci(s);
			else if(s[0] == 'I' || s[0] == 'V')
				ones = procOnes(s);
		}
		int res = 1000 * thou + 100 * hund + 10 * deci + ones;
//		cout << Thou << " " << Hund << " " << Deci << " " << Ones << " " << endl;
		return res;
	}
};

int main(){
	string s = "MCMXCIV";
	Solution A;
	cout << A.romanToInt(s);
	return 0;
}
