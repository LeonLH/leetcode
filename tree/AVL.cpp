#include<iostream>
using namespace  std;
struct AVLNode{
	int val;
	AVLNode* left;
	AVLNode* right;
	int height;
	AVLNode(){};
	AVLNode(int key): val(key), left(NULL), right(NULL), height(1){};

	
	void leftRotate(AVLNode* &T);
	void rightRotate(AVLNode* &T);
	bool insertAVL(AVLNode* &T, int k);
	bool createAVL(AVLNode* &T, int A[], int nlen);

	void printInorderRe(AVLNode* T);
	void printPreorderRe(AVLNode* T);

};

int maxHeight(AVLNode* N1, AVLNode* N2){
	if(!N1 && !N2)
		return 0;
	else if(!N1 &&  N2)
		return N2->height;
	else if( N1 && !N2)
		return N1->height;
	else
		return max(N1->height, N2->height);
}
int GetBalanceFactor(AVLNode* T){
	if(!T)
		return 0;
	else if(!T->left && !T->right)
		return 0;
	else if( T->left && !T->right)
		return T->left->height;
	else if(!T->left &&  T->right)
		return - T->right->height;
	else 
		return T->left->height - T->right->height;
}
void AVLNode::rightRotate(AVLNode* &p){
	AVLNode* lc = p->left;
	p->left = lc->right;
	lc->right = p;
	p->height = 1 + maxHeight(p->left, p->right);
	lc->height = 1 + maxHeight(lc->left, lc->right);
	p = lc;

}
void AVLNode::leftRotate(AVLNode* &p){
	AVLNode* rc = p->right;
	p->right = rc->left;
	rc->left = p;
	p->height = 1 + maxHeight(p->left, p->right);
	rc->height = 1 + maxHeight(rc->left, rc->right);
	p = rc;
}
// 1. Insert as a normal BST;
// 2. Update the height of T;
// 3. Get the balance factor;
// 4. Rotate to ajust the unbalanced tree, there are four condition: LL RR LR RL;
bool AVLNode::insertAVL(AVLNode* &T, int k){
	if(!T){
		T = new AVLNode(k);
		return true;
	}
	AVLNode* p = T;
	if(k == p->val)
		return false;
	if(k < p->val)
		insertAVL(p->left, k);
	else if(k > p->val)
		insertAVL(p->right, k);
	T->height = 1 + maxHeight(T->left, T->right);
	int bf = GetBalanceFactor(T);
	if(bf > 1 && k < T->left->val)
		rightRotate(T);
	else if(bf < -1 && k > T->right->val)
		leftRotate(T);
	else if(bf > 1 && k > T->left->val){
		leftRotate(T->left);
		rightRotate(T);
	}
	else if(bf < -1 && k < T->right->val){
		rightRotate(T->right);
		leftRotate(T);
	}
	return true;

}
bool AVLNode::createAVL(AVLNode* &T, int A[], int nlen){
	if(!T) 
		T = NULL;
	for(int i=0; i<nlen; ++i)
		insertAVL(T, A[i]);
	return true;
}
void AVLNode::printPreorderRe(AVLNode* T){
	if(T){
		cout << T->val << " ";
		printPreorderRe(T->left);
		printPreorderRe(T->right);
	}
}
void AVLNode::printInorderRe(AVLNode* T){
	if(T){
		printInorderRe(T->left);
		cout << T->val << " ";
		printInorderRe(T->right);
	}

}
int main(){
	int A[] = {53, 17, 78, 9, 45, 65, 69, 87, 23, 58};
	AVLNode *T = NULL;
	T->createAVL(T, A, sizeof(A)/sizeof(int));	
	cout << "PreorderRe:\t";
	T->printPreorderRe(T);
	cout << endl;
	cout << "InorderRe:\t";
	T->printInorderRe(T);
	cout << endl;
	return 0;
}
