#include<iostream>
#include<stack>
using namespace std;
typedef struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
	TreeNode(){};

	bool insertBST(TreeNode* &T, int k);
	void createBST(TreeNode* &T, int A[], int nlen);

	TreeNode* searchBST(TreeNode* T, int key, TreeNode* &pare);
	TreeNode* findInorderPrev(TreeNode* T, TreeNode* curr);
	bool deleteBST(TreeNode* &T, int key);

	void printPreorderRe(TreeNode* T);
	void printInorderRe(TreeNode* T);
	void printPreorderIt(TreeNode* T);

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

bool TreeNode::insertBST(TreeNode* &T, int key){
	if(!T){
		T = new TreeNode(key);
		return false;
	}
	else if(key == T->val)
		return true;
	else if(key <  T->val)
		return insertBST(T->left, key);
	else 
		return insertBST(T->right, key);
}

void TreeNode::createBST(TreeNode* &T, int A[], int nlen){
	T = NULL;
	for(int i=0; i<nlen; ++i)
		insertBST(T, A[i]);
}

TreeNode* TreeNode::searchBST(TreeNode* T, int key, TreeNode* &pare){
	if(!T) return NULL;
	TreeNode* p = T;
	while(p != NULL && p->val != key){
		pare = p;
		if(key < p->val) 
			p = p->left;
		else
			p = p->right;
	}
	return p; 
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

void TreeNode::printPreorderIt(TreeNode* T){
	if(!T) return;
	stack<TreeNode*> S;
	S.push(T);
	while(!S.empty()){
		TreeNode* p = S.top();
		cout << p->val << " ";
		S.pop();
		if(p->right)
			S.push(p->right);
		if(p->left)
			S.push(p->left);
	}
}

bool TreeNode::deleteBST(TreeNode* &T, int key){
	if(!T) return 0;
	TreeNode* pare = NULL;
	TreeNode* curr = NULL;
	curr = searchBST(T, key, pare);
	if(!curr) return false;
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
		searchBST(T, prev->val, prevpare);
		curr->val = prev->val;
		if(prev == curr->left)
			curr->left = prev->left;	//prev don't have right child
		else
			prevpare->right = prev->left;//prev don't have right child
		delete prev;
	}
	return true;
}
int main(){
	int A[] = {53, 17, 78, 9, 45, 65, 69, 87, 23};
	TreeNode *T = NULL;
	T->createBST(T, A, sizeof(A)/sizeof(int));
	TreeNode* pare=NULL, * curr=NULL;
	if(T->searchBST(T, 69, pare))
		cout << "Yes!" << endl;
	else
		cout << "No!" << endl;

	T->printPreorderIt(T);
	cout << endl;
	T->printInorderRe(T);
	cout << endl;
	cout << "After Delete:" << endl;
	T->deleteBST(T,78);
	T->printPreorderRe(T);
	cout << endl;
	T->printInorderRe(T);
	cout << endl;
	return 0;
}
