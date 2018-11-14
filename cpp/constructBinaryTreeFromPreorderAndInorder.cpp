// 1.可以使用递归或者非递归的方法，如果使用非递归的方法来构造二叉树
// 		1. Preorder+Inorder: 需要借助一个栈，和一个tag标签数组。具体做法：从Preorder中从前往后走，查找它在Inorder中的位置，并查看它左右两侧有没有空位置：
// 			* 先把Preorder第一个元素入栈；
// 			* 查看栈顶元素的标签数组；
// 			* 左边空，先挂左边，入栈,修改标签；
// 			* 左边不空右边空，挂右边，入栈,修改标签；
// 			* 左边不空右边也不空，出栈；
// 			* 直至栈为空且Preorder也走到了尾部为止；
// 		2. Postorder+Inorder: 它与Preorder+Inorder的方法是类似的，只是它是从Postorder的尾巴从后往前走，每一个数也要查询他在Inorder中的位置，并查看它左右两端是否为空，另一个区别是，若左右都可以插入时，它是优先插入到右子树上的;
// 		3. levelorder+Inorder: 它需要借助一个队列。
// 	2. 这一类问题，如果思路不清晰的话可以花一个稍微复杂一点的图，在纸上跑几遍过程，思路就慢慢的遍清晰了。
// 	3. 采用递归方法，用回溯法；
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
typedef struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {};

}TreeNode, BiTNode, BSTNode, *BiTree;

// divide and conquer method





// iterative method
class Solution{
public:
	TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
        if(preorder.size()==0)
            return NULL;
		int n = preorder.size();
		int *tag = new int[n];
		for(int i=0; i<n; ++i)
			tag[i] = 0;
		int i = 0;
		stack<TreeNode*> S;
		TreeNode* T = new TreeNode(preorder[0]);
		TreeNode *p = T;
		S.push(p);
		int j = PosInInorderVector(preorder[0], inorder);
		int k = 0;
		tag[j] = 1;
		while(i<n||!S.empty()){
			TreeNode *p = S.top();
			if(((j==n-1 && tag[j-1]==0)||(tag[j-1]==0))&&(j-1>=0)){
				TreeNode *newNode = new TreeNode(preorder[i+1]);
				p->left = newNode;
				p = p->left;
				S.push(p);
				k = PosInInorderVector(preorder[i+1], inorder);
				tag[k] = 1;
			}
			else if((j==0 ||tag[j-1] == 1)&&(tag[j+1]==0)&&(j!=n-1)){ 
				TreeNode *newNode = new TreeNode(preorder[i+1]);
				p->right = newNode;
				p = p->right;
				S.push(p);
				k = PosInInorderVector(preorder[i+1], inorder);
				tag[k] = 1;
			}
			else if((tag[j-1] == 1 && tag[j+1] == 1)||(j==0 && tag[j+1]==1)||(j==n-1 && tag[j-1]==1)||(j==0&&n==1)){
			//There are 4 situations, leftest, rightest, middle and only one;
				S.pop();
				if(S.size()==0)
					break;
				p = S.top();
				j = PosInInorderVector(p->val, inorder);
				continue;
			}
			j = k;
			i++;
		}
		return T;

	}
	void printInOrder(TreeNode *T){
		if(T){
			printInOrder(T->left);
			cout << T->val << " " ;
			printInOrder(T->right);
		}
	}
	void printPostOrder(TreeNode *T){
		if(T){
			cout << T->val << " ";
			printPostOrder(T->left);
			printPostOrder(T->right);
		}
	}
	int PosInInorderVector(int o, vector<int>& inorder){
		int n = inorder.size();
		for(int i=0; i<n; ++i)
			if(inorder[i] == o)
				return i;
		return -1;
	}
};
int main(){
	vector<int> preorder = {1, 2, 20, 11, 72, 40, 7, 9, 16, 17, 38, 12, 60};
	vector<int>  inorder = {20, 2, 72, 40, 11, 1, 16, 9, 38, 17, 7, 60, 12};
	vector<int> preorder1 = {3, 9, 20, 15, 7};
	vector<int>  inorder1 = {9, 3, 15, 20, 7};
	TreeNode *T = NULL;
	Solution A;
	T = A.buildTree(preorder1, inorder1);
	A.printInOrder(T);
	cout << endl;
	A.printPostOrder(T);
	cout << endl;
	return 0;
}
