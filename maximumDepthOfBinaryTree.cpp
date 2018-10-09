#include"Tree/Tree.cpp"
//用循环的方法遍历一遍，记录栈的最大高度；后序遍历
class Solution{
public:
	int depth = 0;
	int maxDepth1(TreeNode* root){
		if(!root) return 0;

		depth = 1 + max(maxDepth1(root->left), maxDepth1(root->right));
		return depth;
	}
	int maxDepth(TreeNode* root){
		if(!root) return 0;
		TreeNode* prev = NULL;
		TreeNode* curr = NULL;
		stack<TreeNode*> S;
		int h = 0;
		S.push(root);
		++h;
		int max = h;
		while(!S.empty()){
			curr = S.top();
			if(!prev || prev->left == curr || prev->right == curr){
				if(curr->left){
					S.push(curr->left);
					++h;
					max = ((max>h) ? max : h);
				}
				else if(curr->right){
					S.push(curr->right);
					++h;
					max = ((max>h) ? max : h);
				}
				else{
					S.pop();
					--h;
				}
			}
			else if(curr->left == prev){
				if(curr->right){
					S.push(curr->right);
					++h;
					max = ((max>h) ? max : h);
				}
				else{
					S.pop();
					--h;
				}
			}
			else if(curr->right == prev){
				S.pop();
				--h;
			}
			prev = curr;
		}
		return max;
	}
};
int main(){
//	int preorder[] = {3, 9, 20, 15, 7};
//	int  inorder[] = {9, 3, 15, 20, 7};
	int preorder[] = {1, 2, 20, 11, 72, 40, 7, 9, 16, 17, 38, 12, 60};
	int  inorder[] = {20, 2, 72, 40, 11, 1, 16, 9, 38, 17, 7, 60, 12};
	TreeNode* T = NULL;
	T = T->createTree(preorder, inorder, sizeof(preorder)/sizeof(int));
	Solution A;
	int n = A.maxDepth1(T);
	cout << n << endl;
	return 0;
}
