#include<iostream>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;
typedef struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {};
	TreeNode();
	TreeNode* createTree(int preorder[], int inorder[], int n);
	int PosInInorder(int x, int* inorder, int n);

	void printInorderRe(TreeNode *T);
	void printPreorderRe(TreeNode *T);
	void printPostorderRe(TreeNode *T);

	void printInorderIt(TreeNode *T);
	void printPreorderIt(TreeNode *T);
	void printPostorderIt(TreeNode *T);

}TreeNode, BiTNode, BSTNode, *BiTree;
