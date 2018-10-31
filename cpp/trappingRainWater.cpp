#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class Solution{
public:
	int trap(vector <int> &height){
	//0.Abnormal inspection;
	//1.Loop1 from vector[0]->vector[max], loop2 from vector[end]->vector[max];
	//2.Push every number in stack, if the number is smaller than stack's bottom number;
	//3.Once encounter a larger number, pop stack to empty and calculate water;
	//4.Sum the water;
	//ps: calculate water:stack's element sum the height_difference between the first and itself;
		if(height.size()<=2) return 0;
		stack<int> H;
		int sum_water = 0;
		int max = 0;
		vector<int>::iterator max_it;
		for(vector<int>::iterator it = height.begin(); it!=height.end(); ++it)
			if(*it>max){
				max_it = it;
				max = *it;
			}
		int first = height.front();
		for(vector<int>::iterator it = height.begin(); it != max_it+1; ++it){
			if(*it >= first){
				sum_water += calculate_water(H, first);		//There can be more effectioncy
				H.push(*it);
				first = *it;
			}
			else
				H.push(*it);
		}
		H.pop();	//empty the stack;
		first = height.back();
		for(vector<int>::iterator it = height.end()-1; it != max_it-1; --it){
			//repeat above;
			if(*it >= first){
				sum_water += calculate_water(H, first);
				H.push(*it);
				first = *it;
			}
			else
				H.push(*it);
		}
		return sum_water;
	}
	int calculate_water(stack<int>& H, int first){
		int sum_stack = 0;
		if(H.empty()) return 0;
		while(!H.empty()){
			sum_stack += (first-H.top());
			H.pop();
		}
		return sum_stack;
	}
};
int main(){
	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	Solution A;
	cout << A.trap(height) <<endl;
	cin.get();
	return 0;
}
