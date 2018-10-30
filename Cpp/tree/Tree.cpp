#include<iostream>
#include<queue>
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
	void printLevelorderRe(TreeNode *T);

	void printInorderIt(TreeNode *T);
	void printPreorderIt(TreeNode *T);
	void printPostorderIt(TreeNode *T);
	void printLevelorderIt(TreeNode *T);

}TreeNode, BiTNode, BSTNode, *BiTree;


void TreeNode::printInorderRe(TreeNode *T){
	if(T){
		printInorderRe(T->left);
		cout << T->val << " " ;
		printInorderRe(T->right);
	}
}
void TreeNode::printPostorderRe(TreeNode *T){
	if(T){
		printPostorderRe(T->left);
		printPostorderRe(T->right);
		cout << T->val << " ";
	}
}
void TreeNode::printPreorderRe(TreeNode *T){
	if(T){
		cout << T->val << " ";
		printPreorderRe(T->left);
		printPreorderRe(T->right);
	}
}
void TreeNode::printLevelorderIt(TreeNode *T){
	if(!T) return;
	TreeNode* p = NULL;
	queue<TreeNode*> Q;
	Q.push(T);
	while(!Q.empty()){
		p = Q.front();
		cout << p->val << " ";
		Q.pop();
		if(p->left)
			Q.push(p->left);
		if(p->right)
			Q.push(p->right);
	}

}
void TreeNode::printPreorderIt(TreeNode *T){
	if(!T)	return;
	stack<TreeNode*> S;
	S.push(T);
	while(!S.empty()){
		TreeNode *p = S.top();
		cout << p->val << " ";
		S.pop();
		if(p->right)
			S.push(p->right);
		if(p->left)
			S.push(p->left);
	}
}
void TreeNode::printInorderIt(TreeNode *T){
	TreeNode *p = T;
	stack<TreeNode*> S;
	while(p || !S.empty()){
		if(p){
			S.push(p);
			p = p->left;
		}
		else{
			p = S.top();
			S.pop();
			cout << p->val << " ";
			p = p->right;
		}
	}
}
void TreeNode::printPostorderIt(TreeNode *T){
	if(!T) return ;
	stack<TreeNode*> S;
	S.push(T);
	TreeNode *prev = NULL;
	TreeNode *curr = NULL;
	while(!S.empty()){
		curr = S.top();
		if(!prev || prev->left == curr || prev->right == curr){
			if(curr->left)
				S.push(curr->left);
			else if(curr->right)
				S.push(curr->right);
			else{
				cout << curr->val << " ";
				S.pop();
			}
		}
		else if (curr->left == prev){
			if(curr->right)
				S.push(curr->right);
			else{
				cout << curr->val << " ";
				S.pop();
			}
		}
		else if(curr->right == prev){
			cout << curr->val << " ";
			S.pop();
		}
		prev = curr;
	}

}
int TreeNode::PosInInorder(int o, int* inorder, int n){
	for(int i=0; i<n; ++i)
		if(inorder[i] == o)
			return i;
	return -1;
}
TreeNode* TreeNode::createTree(int preorder[], int inorder[], int n){
	if(n==0) return NULL;
	int *tag = new int[n];
	for(int i=0; i<n; ++i)
		tag[i] = 0;
	int i = 0;
	stack<TreeNode*> S;
	BiTree T = new TreeNode(preorder[0]);
	TreeNode *p = T;
	S.push(p);
	int j = PosInInorder(preorder[0], inorder, n);
	int k = 0;
	tag[j] = 1;
	while(i<n||!S.empty()){
		TreeNode *p = S.top();
		if(((j==n-1 && tag[j-1]==0)||(tag[j-1]==0))&&(j-1>=0)){
			TreeNode *newNode = new TreeNode(preorder[i+1]);
			p->left = newNode;
			p = p->left;
			S.push(p);
			k = PosInInorder(preorder[i+1], inorder, n);
			tag[k] = 1;
		}
		else if((j==0 ||tag[j-1] == 1)&&(tag[j+1]==0)&&(j!=n-1)){ 
			TreeNode *newNode = new TreeNode(preorder[i+1]);
			p->right = newNode;
			p = p->right;
			S.push(p);
			k = PosInInorder(preorder[i+1], inorder, n);
			tag[k] = 1;
		}
		else if((tag[j-1] == 1 && tag[j+1] == 1)||(j==0 && tag[j+1]==1)||(j==n-1 && tag[j-1]==1)||(j==0&&n==1)){
			S.pop();
			if(S.size()==0)
				break;
			p = S.top();
			j = PosInInorder(p->val, inorder, n);
			continue;
		}
		j = k;
		i++;
	}
	return T;

}
int main(){
	int preorder1[] = {1, 2, 20, 11, 72, 40, 7, 9, 16, 17, 38, 12, 60};
	int  inorder1[] = {20, 2, 72, 40, 11, 1, 16, 9, 38, 17, 7, 60, 12};
	int preorder2[] = {1, 2, 4, 5, 3};
	int  inorder2[] = {4, 2, 5, 1, 3};
	int preorder[] = {53, 17, 9, 45, 23, 78, 65, 87};
	int  inorder[] = {9, 17, 23, 45, 53, 65, 78, 87};
	TreeNode *T = NULL;
	T = T->createTree(preorder, inorder, sizeof(preorder)/sizeof(int));
//	cout << "printLevelorderIt: \t" ;
//	T->printLevelorderIt(T);
//	cout << endl;
	cout << "printPreorderRe: \t" ;
	T->printPreorderRe(T);
	cout << endl;
	cout << "printPreorderIt: \t" ;
	T->printPreorderIt(T);
	cout << endl;
//	cout << "printInorderRe: \t" ;
//	T->printInorderRe(T);
//	cout << endl;
//	cout << "printInorderIt: \t" ;
//	T->printInorderIt(T);
//	cout << endl;
//	cout << "printPostorderRe: \t" ;
//	T->printPostorderRe(T);
//	cout << endl;
//	cout << "printPostorderIt: \t" ;
//	T->printPostorderIt(T);
//	cout << endl;
	return 0;
}
