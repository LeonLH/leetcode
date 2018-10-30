#include"Tree/Tree.cpp"
class Solution{
public:
	void pushBackIntoVector(vector<TreeNode*> Vtmp, vector<vector<int>> &V){
		if(Vtmp.empty()) return;
		vector<int> Vint;
		if(!(V.size()%2)){
			for(int i=0; (unsigned)i<Vtmp.size(); ++i)
				Vint.push_back(Vtmp[i]->val);
		}	
		else{
			for(int i=Vtmp.size()-1; i>=0; --i)
				Vint.push_back(Vtmp[i]->val);
		}
		V.push_back(Vint);
	}
	bool haveParentInCurrentLevel(TreeNode* p, vector<TreeNode*> V){
		if(V.empty()) return false;
		for(int i=0; (unsigned)i<V.size(); ++i){
			if(V[i]->left == p || V[i]->right == p)
				return true;
		}
		return false;
	}
	vector<vector<int>> zigzagLevelOrder(TreeNode* root){
		vector<vector<int>> V;
		vector<TreeNode*> Vtmp;
		queue<TreeNode*> Q;
		TreeNode* p = NULL;
		if(!root) return V;
		Q.push(root);
		while(!Q.empty()){
			p = Q.front();
			Q.pop();
			if(haveParentInCurrentLevel(p, Vtmp)){
				pushBackIntoVector(Vtmp, V);
				Vtmp.clear();
				Vtmp.push_back(p);
			}
			else
				Vtmp.push_back(p);
			if(p->left)
				Q.push(p->left);
			if(p->right)
				Q.push(p->right);

		}
        pushBackIntoVector(Vtmp, V);
	return V;
	}
	void printVecVec(vector<vector<int>> V){
		for(int i=0; (unsigned)i<V.size(); ++i){
			vector<int> tmp = V[i];
			for(int j=0; (unsigned)j<tmp.size(); ++j){
				cout << tmp[j] << " ";
			}
			cout << endl;
		}
	}
};
int main(){
	int preorder1[] = {1, 2, 20, 11, 72, 40, 7, 9, 16, 17, 38, 12, 60};
	int  inorder1[] = {20, 2, 72, 40, 11, 1, 16, 9, 38, 17, 7, 60, 12};
	int preorder[] = {3, 9, 20, 15, 7};
	int  inorder[] = {9, 3, 15, 20, 7};
	TreeNode* T = NULL;
	T = T->createTree(preorder1, inorder1, sizeof(preorder1)/sizeof(int));
	T->printPreorderRe(T);
	cout << endl;
	T->printInorderRe(T);
	cout << endl;
	Solution A;
	vector<vector<int>> V = A.zigzagLevelOrder(T);
	A.printVecVec(V);

	return 0;
}
