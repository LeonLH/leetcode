// #106 Populating Next Right Pointer in Each Node
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}


};
class Solution {
public:
    void connect(TreeLinkNode *T) {
        if(T == NULL) return;
        queue<TreeLinkNode *> Q;
        Q.push(T);
        TreeLinkNode * prev = NULL;
        TreeLinkNode * curr = NULL;

        while(!Q.empty()) {
            int tmp_size = Q.size();

			prev = curr = NULL;
            for (int i = 0; i < tmp_size; i++) {
                curr = Q.front();
                Q.pop();

                if(prev) 
					prev->next = curr;
                prev = curr;

                if(curr->left)
					Q.push(curr->left);
                if(curr->right)
					Q.push(curr->right);
				
				curr = NULL;		// Why adding this line can speed up program by 25%? This line can also be removed. 
            }
            prev->next = NULL;
        }
    }
};
class Solution1 {
public:
	bool isStartOfLevel(TreeLinkNode* p, vector<TreeLinkNode*> v){
		for(int i=0; (unsigned)i < v.size(); ++i){
			if(v[i]->left == p || v[i]->right == p)
				return true;
		}
		return false;
	}
	void connect(TreeLinkNode* T){
		if(!T)
			return;
		queue<TreeLinkNode*> Q;
		vector<TreeLinkNode*> tmpV;
		TreeLinkNode* p = NULL;
		TreeLinkNode* prev = NULL;
		Q.push(T);
		while(!Q.empty()){
			p = Q.front();
			Q.pop();

			if(prev == NULL){
				tmpV.push_back(p);
			}
			else if(isStartOfLevel(p, tmpV)){
				prev->next = NULL;
				tmpV.clear();
				tmpV.push_back(p);
			}
			else{
				prev->next = p;
				tmpV.push_back(p);
			}
			prev = p;

			if(p->left)
				Q.push(p->left);
			if(p->right)
				Q.push(p->right);
		}
	}
};
TreeLinkNode* createTreeFromLevelOrder(int A[], int nlen){
	TreeLinkNode* p = NULL;
	TreeLinkNode* T = NULL;
	queue<TreeLinkNode*> Q;
	if(!nlen)
		return NULL;
	else{
		T = new TreeLinkNode(A[0]);
	}
	Q.push(T);
	int i = 0;
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		++i;
		if(A[i]){
			TreeLinkNode* pleft = new TreeLinkNode(A[i]);
			p->left = pleft;
			Q.push(pleft);
		}
		else
			p->left = NULL;
		if(i == nlen-1)
			break;

		++i;
		if(A[i]){
			TreeLinkNode* pright = new TreeLinkNode(A[i]);
			p->right = pright;
			Q.push(pright);
		}
		else 
			p->right = NULL;
		if(i == nlen-1)
			break;
	}
	return T;
}
void printInorderIt(TreeLinkNode* T){
	TreeLinkNode* p = T;
	stack<TreeLinkNode*> S;
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
void printPreorderIt(TreeLinkNode* T){
	TreeLinkNode* p = NULL;
	stack<TreeLinkNode*> S;
	S.push(T);
	while(!S.empty()){
		p = S.top();
		S.pop();
		cout << p->val << " ";
		if(p->right)
			S.push(p->right);
		if(p->left)
			S.push(p->left);
	}
}
int main(){
	int A[] = {1, 2, 3, 0, 5, 0, 7};
	TreeLinkNode* T = createTreeFromLevelOrder(A, sizeof(A)/sizeof(int));
	cout << "\tInorder:\t" ;
	printInorderIt(T);
	cout << endl;
	cout << "\tPreorder:\t";
	printPreorderIt(T);
	cout << endl;

	return 0;
}


// Levelorder traversal, and then put the every rightest node's next to NULL. 
// A problem about levelorder's level number, how to decide it's time to switch level:
// 		Method 1: Current node's parent is the same level as itself, It's time to switch level; 
// 		Method 2: Using a small for loop inside the big while loop, each forloop is a traversal of a whole level, and the big whileloop is travarsal the whole tree. Concretely, before the forloop We record the size of queue, and this size is the number of current level, so we can use it in with forloop. 
