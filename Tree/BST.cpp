#include<iostream>
#include<stack>
using namespace std;
typedef struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
	TreeNode(){};

	int insertBST(TreeNode* &T, int k);
	void createBST(TreeNode* &T, int A[], unsigned int nlen);

	TreeNode* searchBST(TreeNode* T, int key, TreeNode* &pare);
	TreeNode* findInorderPrev(TreeNode* T, TreeNode* curr);
	int deleteBST(TreeNode* &T, int key);

	void printPreorderRe(TreeNode* T);
	void printInorderRe(TreeNode* T);

}BSTNode, *BiTree;

void TreeNode::printInorderRe(TreeNode* T){
	if(T){ 
		printInorderRe(T->left);
		cout << T->val << " ";
		printInorderRe(T->right);
	}	
}

void TreeNode::printPreorderRe(TreeNode* T){
	if(T){ 
		cout << T->val << " ";
		printPreorderRe(T->left);
		printPreorderRe(T->right);
	}	
}

int TreeNode::insertBST(BiTree &T, int key){
	if(!T){
		T = new TreeNode;
		T->val = key;
		T->left = T->right = NULL;
		return 1;
	}
	else if(key == T->val)
		return 0;
	else if(key <  T->val)
		return insertBST(T->left, key);
	else 
		return insertBST(T->right, key);
}

void TreeNode::createBST(BiTree &T, int A[], unsigned int nlen){
	T = NULL;
	for(int i=0; (unsigned)i<nlen; ++i)
		insertBST(T, A[i]);
}

TreeNode* TreeNode::searchBST(TreeNode* T, int key, TreeNode* &pare){
	if(!T) return NULL;
	TreeNode* p = T;
	TreeNode* curr;
	pare = curr = NULL;
	while(p != NULL && p->val != key){
		pare = p;
		if(key < p->val) 
			p = p->left;
		else
			p = p->right;
	}
	if(p && key == p->val)
		curr = p;
	return curr; 
}

TreeNode* TreeNode::findInorderPrev(TreeNode* T, TreeNode* obj){
	TreeNode* prev = NULL;
	TreeNode* p = T;
	stack<TreeNode*> S;
	while(p || !S.empty()){
		if(p){
			S.push(p);
			p = p->left;
		}
		else{
			p = S.top();
			S.pop();
			if(p == obj)		//visit
				return prev;	//visit
			prev = p;			//visit
			p = p->right;
		}
	}
	return prev;
}


int TreeNode::deleteBST(TreeNode* &T, int key){
	if(!T) return 0;
	TreeNode* pare = NULL;
	TreeNode* curr = NULL;
	//if(!searchBST(T, key, pare, curr)) return 0;
	curr = searchBST(T, key, pare);
	if(!curr) return 0;
	if(!curr->left && !curr->right){
		if(!pare)
			T = NULL;
		else if(pare->left == curr)
			pare->left = NULL;	
		else if(pare->right == curr)
			pare->right = NULL;
		delete curr;
	}
	else if(curr->left && !curr->right){
		if(!pare)
			T = curr->left;
		else if(pare->left == curr)
			pare->left = curr->left;
		else if(pare->right == curr)
			pare->right = curr->left;
		delete curr;
	}
	else if(curr->right && !curr->left){
		if(!pare)
			T = curr->right;
		else if(pare->left == curr)
			pare->left = curr->right;
		else if(pare->right == curr)
			pare->right = curr->right;
		delete curr;
	}
	else if(curr->left && curr->right){
		TreeNode* prev = NULL, * prevpare = NULL;
		prev = findInorderPrev(T, curr);
		//searchBST(T, prev->val, prevpare, prev);
		searchBST(T, prev->val, prevpare);
		curr->val = prev->val;
		prevpare->right = prev->left;
		delete prev;
	}
	return 1;
}
int main(){
	int A[] = {53, 17, 78, 9, 45, 65, 69, 87, 23};
	TreeNode *T = NULL;
	T->createBST(T, A, sizeof(A)/sizeof(int));
	TreeNode* pare=NULL, * curr=NULL;
	cout << T->searchBST(T, 9, pare) << endl;

	T->printPreorderRe(T);
	cout << endl;
	T->printInorderRe(T);
	cout << endl;
	cout << "After Delete:" << endl;
	T->deleteBST(T,69);
	T->printPreorderRe(T);
	cout << endl;
	T->printInorderRe(T);
	cout << endl;
	return 0;
}
