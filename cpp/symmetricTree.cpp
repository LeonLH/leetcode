// 1. The result of Inorder traversal and Reverse-Inorder traversal are equal.
// 2. The key of the problem is not only the val of node should be equal, but also the pointer should be symmetric.
// 3. BUT inorder and preorder can define an unique tree, so 'inorder equals to reInorder' PLUS 'preorder equals to rePreorder' can make sure it is symmetric. 
<<<<<<< HEAD
// There must be a better way for this problem. 


=======
>>>>>>> f35bc06... #101 1H S

#include<vector>
#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution{
public:
	void inorder(TreeNode* T, vector<int> &V);
	void reInorder(TreeNode* T, vector<int> &RV);
	void preorder(TreeNode* T, vector<int> &V);
	void rePreorder(TreeNode* T, vector<int> &RV);
	bool isSymmetric(TreeNode* root){
		vector<int> inorderV, inorderRV;
		vector<int> preorderV, preorderRV;
		inorder(root, inorderV);
		reInorder(root, inorderRV);
		preorder(root, preorderV);
		rePreorder(root, preorderRV);
		if(inorderV == inorderRV && preorderV == preorderRV)
			return true;
		else
			return false;
	}
};
void Solution::preorder(TreeNode* T, vector<int> &V){
	if(T){
		V.push_back(T->val);
		preorder(T->left, V);
		preorder(T->right, V);
	}	
}
void Solution::rePreorder(TreeNode* T, vector<int> &V){
	if(T){
		V.push_back(T->val);
		rePreorder(T->right, V);
		rePreorder(T->left, V);
	}	
}
void Solution::inorder(TreeNode* T, vector<int> &V){
	if(T){
		inorder(T->left, V);
		V.push_back(T->val);
		inorder(T->right, V);
	}	
}
void Solution::reInorder(TreeNode* T, vector<int> &RV){
	if(T){
		reInorder(T->right, RV);
		RV.push_back(T->val);
		reInorder(T->left, RV);
	}
}
int main(){

	return 0;
}
