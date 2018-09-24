#include<stack>
#include<vector>
#include<iostream>
using namespace std;
//0
//1. 遍历每一个竖条，每次计算它和左边边界围城的面积，需要高度和宽度；
//2. 高度有两种可能性：1）自身的高；2）最低条的高；
//3. 宽度需要两个数据：1）自身的下标；2）左界限的下标；
//4. 计算左界限：1）最低条的下标；2）pop到稍微高于当前条的下标；
//ps:在遍历的过程中会遇到两种情况：
// 		1）当前条大于前一条(递增)，则push进记录左界限的stack中；
// 		2）当前条小于前一条(递减)，则pop到比当前条稍稍大一点的条停止；
//Speak in English:
//0. 
//1. Traverse every bars from left to right, every bar correspond to a rectangle, after traverse we also traversed every possible rectangle, in this problem. To calculate the area, we need HEIGHT and WIDTH;
//2. HEIGHT have two possibilites: 1) bar's height; 2) lowest bar's height;
//3. WIDTH need two data: 1) bar's subscript; 2) left limit subscript;
//4. Left limit: 1) 0; 2) lowest bar's subscript;
//ps: There are two situation when we traverse:
// 		1) Current bar is higher than previous bar(Increment), then we push to a stack which record the left_index of rectangle;
// 		2) Current bar is lower than previous bar(Decrement), then we pop above stack until the stack's top is a little lower than current bar;
class Solution {
public:
	int largestRectangleArea(vector<int>& height){
		stack<int> sHeight;
		stack<int> sLeft;
		int left = 0 ;
		int pre = 0;
		int maxArea = 0;
		int tmpArea = 0;
		for(unsigned int i = 0; i < height.size(); ++i){
			if(i==0){
				sHeight.push(height[i]);
				left = i;
				sLeft.push(left);
				continue;
			}
			if(height[i] > sHeight.top()){		//consider 0 after a while
				sHeight.push(height[i]);
				tmpArea = (i-left+1)*height[left];
				if(tmpArea > maxArea)
					maxArea = tmpArea;
			}
			else{
				while(sHeight.top() >= height[i]){
					sHeight.pop();
					--left;
				}
				sHeight.push(height[i]);
				tmpArea = (i-left+1)*sHeight.top();
				if(tmpArea > maxArea)
					maxArea = tmpArea;
				pre = height[i];

			}
		}
		return maxArea;
	}

};
int main(){
	vector<int> height = {2, 1, 5, 6, 2, 3};
	return 0;
}
