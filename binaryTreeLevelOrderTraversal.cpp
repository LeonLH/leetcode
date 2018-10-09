#include"Tree/Tree.cpp"
#include<vector>
#include<queue>
class Solution{
public:
	bool haveParentInCurrentLevel(TreeNode *p, vector<TreeNode*> V){
		if(V.empty()) return false;
		for(int i=0; (unsigned)i<V.size(); ++i){
			if(V[i]->right == p || V[i]->left == p)
				return true;
		}
		return false;
	}
	vector<vector<int>> levelOrder(TreeNode* root){
		vector<vector<int>> res;
		vector<int> tmp;
		vector<TreeNode*> tmpNode;
		queue<TreeNode*> Q;
		TreeNode *p = root;
		Q.push(p);
		if(!root) return res;
		while(!Q.empty()){
			p = Q.front();
			Q.pop();
			if(haveParentInCurrentLevel(p, tmpNode)){
				res.push_back(tmp);
				tmp.clear();
				tmpNode.clear();
				tmp.push_back(p->val);
				tmpNode.push_back(p);
			}
			else{
				tmp.push_back(p->val);	
				tmpNode.push_back(p);
			}
			if(p->left)
				Q.push(p->left);
			if(p->right)
				Q.push(p->right);
		}
		res.push_back(tmp);
		return res;
	}
};
int main(){
	int preorder[] = {3, 9, 20, 15, 7};
	int  inorder[] = {9, 3, 15, 20, 7};
	TreeNode* T = NULL;
	T = T->createTree(preorder, inorder, sizeof(preorder)/sizeof(int));
	Solution A;
	vector<vector<int>> res = A.levelOrder(T);

	for(int i=0; (unsigned)i<res.size(); ++i){
		cout << "[" ;
		for(int j=0; (unsigned)j<res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << "]";
		cout << "\n";
	}
	return 0;
}
