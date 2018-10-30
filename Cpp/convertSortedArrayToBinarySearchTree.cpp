// 1. Methode 1: Create an AVL tree, using an usual method;
// 2. Methode 2: Divide the array into two part by the middle subnote, 
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
	int val;
	TreeNode*  left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};
void printInorderRe(TreeNode* T){
	if(T){
		printInorderRe(T->left);
		cout << T->val << " ";
		printInorderRe(T->right);
	}
}
void printPreorderRe(TreeNode* T){
	if(T){
		cout << T->val << " ";
		printPreorderRe(T->left);
		printPreorderRe(T->right);
	}
}
void printPreorderIt(TreeNode* T){
	TreeNode* p = NULL;
	stack<TreeNode*> S;
	S.push(T);
	while(!S.empty()){
		p = S.top();
		cout << p->val << " ";
		S.pop();
		if(p->right)
			S.push(p->right);
		if(p->left)
			S.push(p->left);
	}

}
void printInorderIt(TreeNode* T){
	TreeNode* p = T;
	stack<TreeNode*> S;
	while(p || !S.empty()){
		if(p){
			S.push(p);
			p = p->left;
		}
		else{
			p = S.top();
			cout << p->val << " ";
			S.pop();
			p = p->right;
		}
	}
}
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums){
		if(!nums.size())
			return NULL;
		int mid = nums.size()/2;
		TreeNode* p = new TreeNode(nums[mid]);
		vector<int> leftVec, rightVec;

		for(int i=0; i<mid; ++i)
			leftVec.push_back(nums[i]);
		for(int i=mid+1; (unsigned)i<nums.size(); ++i)
			rightVec.push_back(nums[i]);
		p->left = sortedArrayToBST(leftVec);
		p->right = sortedArrayToBST(rightVec);
		return p;
	}
}; 


int main(){
	int A[] = {9, 17, 23, 45, 53, 65, 69, 78, 87};
	vector<int> V;
	for(int i=0; (unsigned)i < (sizeof(A)/sizeof(int)) ; ++i)
		V.push_back(A[i]);
	Solution S;
	TreeNode* T = S.sortedArrayToBST(V);
	cout << "PreorderRe:\t" ;
	printPreorderRe(T);
	cout << endl;
	cout << "InorderRe:\t";
	printInorderRe(T);
	cout << endl;
	cout << "PreorderIt:\t";
	printPreorderIt(T);
	cout << endl;
	cout << "InorderIt:\t";
	printInorderIt(T);
	cout << endl;
	
	
	return 0;
}
