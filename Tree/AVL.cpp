#include<algorithm>
#include<iostream>
using namespace std;
struct AVLNode{
	int key;
	AVLNode* left;
	AVLNode* right;
	int height;

	AVLNode(){};
	AVLNode(int x): key(x), left(nullptr), right(nullptr), height(1) {};

	void rightRotate(AVLNode* &p);
	void  leftRotate(AVLNode* &p);
	void  insert(AVLNode* &node, int key);

	void printInorder(AVLNode* T);
};

int maxHeight(AVLNode* node1, AVLNode* node2){
	if(!node1 && !node2)
		return 0;
	if(!node1 &&  node2)
		return node2->height;
	if( node1 && !node2)
		return node1->height;
	return max(node1->height, node2->height);
}

int getBalance(AVLNode* node){
	if(!node) return 0;
	if(!node->left && !node->right)
		return 0;
	if(!node->left &&  node->right)
		return 0 - node->right->height;
	if( node->left && !node->right)
		return node->left->height;
	return node->left->height - node->right->height;	
}

void AVLNode::rightRotate(AVLNode* &p){
	AVLNode* lc = p->left;
	p->left = lc ->right;
	lc->right = p;
	//Update p's height first, then update lc's height.
	p->height = 1 + maxHeight(p->left, p->right);
	lc->height = 1 + maxHeight(lc->left, lc->right);
	p = lc;
}

void AVLNode::leftRotate(AVLNode* &p){
	AVLNode* rc = p->right;
	p->right = rc->left;
	rc->left = p;
	p->height = 1 + maxHeight(p->left, p->right);		//1 represents p itself. 
	rc->height = 1 + maxHeight(rc->left, rc->right);
	p = rc;
}

void AVLNode::insert(AVLNode* &node, int key){
	if(!node)
		node = new AVLNode(key);
	if(key < node->key)
		insert(node->left, key);
	else if(key > node->key)
		insert(node->right, key);
	node->height = 1 + maxHeight(node->left, node->right);
	int balance = getBalance(node);
	if(balance > 1 && key < node->left->key)
		rightRotate(node);
	if(balance < -1 && key > node->right->key)
		leftRotate(node);
	if(balance > 1 && key > node->left->key){
		leftRotate(node->left);
		rightRotate(node);
	}
	if(balance < -1 && key < node->right->key){
		rightRotate(node->right);
		leftRotate(node);
	}
}

void AVLNode::printInorder(AVLNode* T){
	if(T){
		printInorder(T->left);
		cout << T->key << " ";
		printInorder(T->right);
	}
}

int main(){
	AVLNode* T = NULL;
	int A[] = {1, 2, 20, 11, 72, 40, 7, 9, 16, 17, 38, 12, 60};
	int n = sizeof(A)/sizeof(int);
	for(int i=0; i<n; ++i)
		T->insert(T, A[i]);
	T->printInorder(T);
	cout << endl;
	return 0;
}
