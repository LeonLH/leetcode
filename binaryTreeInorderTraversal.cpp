//#94 Binary Tree Inorder Traversal
#include<iostream>
#include<vector>
#include<stack>
#include"Tree/Tree.cpp"
using namespace std;
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> V;
		TreeNode* p = root;
		stack<TreeNode*> S;
		while(p || !S.empty()){
			if(p){
				S.push(p);
				p = p->left;
			}
			else{
				p = S.top();
				S.pop();
				V.push_back(p->val);
				p = p->right;
			}
		}
		return V;
	}
};
int main(){
	int preorder[] = {1, 2, 4, 5, 3};
	int  inorder[] = {4, 2, 5, 1, 3};
	TreeNode *T = NULL;
	T = T->createTree(preorder, inorder, sizeof(preorder)/sizeof(int));
	Solution A;
	vector<int> res = A.inorderTraversal(T);
	
	for(int i=0; (unsigned)i<res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}
