#include"Tree/Tree.cpp"
class Solution{
public:
	//单纯的确保每个节点的左右子树有序不能确保整棵树是BST。本题用BST的中序遍历的结果是递增的这一性质。
	bool isVal(TreeNode* p){
		if(p->left && p->right){
			if(p->val > p->left->val && p->val < p->right->val)
				return true;
			else
				return false;
		}
		else if(p->left){
			if(p->left->val < p->val)
				return true;
			else
				return false;
		}
		else if(p->right){
			if(p->right->val > p->val)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	bool isValidBST(TreeNode* root){
		if(!root) return true;
		TreeNode* p = root;
		stack<TreeNode*> S;
		vector<int> V;
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
		for(int i=0; (unsigned)i<V.size()-1; ++i){
			if(V[i]>=V[i+1])
				return false;
		}
		return true;
	}

};
int main(){
//	int preorder[] = {1, 2, 20, 11, 72, 40, 7, 9, 16, 17, 38, 12, 60};
//	int  inorder[] = {20, 2, 72, 40, 11, 1, 16, 9, 38, 17, 7, 60, 12};
//	int preorder[] = {53, 17, 9, 45, 23, 78, 65, 87};
//	int  inorder[] = {9, 17, 23, 45, 53, 65, 78, 87};
	int preorder[] = {10, 5, 15, 6, 20};
	int  inorder[] = {5, 10, 6, 15, 20};
	TreeNode *T = NULL;
	T = T->createTree(preorder, inorder, sizeof(preorder)/sizeof(int));
	Solution A;
	int a = A.isValidBST(T);
	if(a)
		cout << "Yes!";
	else
		cout << "No!";
	cout << "printPreorderRe: \t" ;
	T->printPreorderRe(T);
	cout << endl;
	cout << "printInorderRe: \t" ;
	T->printInorderRe(T);
	cout << endl;
	cout << "printPostorderRe: \t" ;
	T->printPostorderRe(T);
	cout << endl;
	return 0;
}
