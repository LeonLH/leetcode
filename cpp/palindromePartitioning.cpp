#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
private:
	vector<vector<string>> resv;
	vector<string> vtmp;
public:
	bool isValid(string &str){				// Add & makes 16ms to 8ms, so it makes a great progress.
		int n = str.size();
		for(int i = 0; i < n/2; ++i){
			if(str[i] == str[n-i-1])
				continue;
			else
				return false;
		}
		return true;
	}

	void solve(string &left){
		if(!left.size()){
			resv.push_back(vtmp);
		}
		else{
			for(int i = 1; (unsigned)i <= left.size(); ++i){
				string stmp = left.substr(0, i);
				if(isValid(stmp)){
					vtmp.push_back(stmp);
					left = left.substr(i);
					solve(left);
					if(vtmp.size() >= 1)				// recover to the customary situation
						vtmp.erase(vtmp.end()-1);
					left = stmp + left;
				}
			}
		}
	}

	vector<vector<string>> partition(string s){
		solve(s);
		return resv;
	}
};

void printVV(vector<vector<string>> v){
	cout << "[\n";
	for(unsigned int i = 0; i < v.size(); i++){
		cout << "  [ ";
		for(unsigned int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << "]\n";
	}
	cout << "]";
}

int main(){
	string str = "abcdc";
	Solution A;
	vector<vector<string>> resv;
	resv = A.partition(str);
	vector<string> v;
	printVV(resv);
	return 0;
}
