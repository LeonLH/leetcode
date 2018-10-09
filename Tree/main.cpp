#include"Tree.cpp"
int main(){
	int preorder[] = {1, 2, 20, 11, 72, 40, 7, 9, 16, 17, 38, 12, 60};
	int  inorder[] = {20, 2, 72, 40, 11, 1, 16, 9, 38, 17, 7, 60, 12};
	int preorder1[] = {1, 2, 4, 5, 3};
	int  inorder1[] = {4, 2, 5, 1, 3};
	TreeNode *T = NULL;
	T = T->createTree(preorder, inorder, sizeof(preorder)/sizeof(int));
	cout << "printPreorderRe: \t" ;
	T->printPreorderRe(T);
	cout << endl;
	cout << "printPreorderIt: \t" ;
	T->printPreorderIt(T);
	cout << endl;
	cout << "printInorderRe: \t" ;
	T->printInorderRe(T);
	cout << endl;
	cout << "printInorderIt: \t" ;
	T->printInorderIt(T);
	cout << endl;
	cout << "printPostorderRe: \t" ;
	T->printPostorderRe(T);
	cout << endl;
	cout << "printPostorderIt: \t" ;
	T->printPostorderIt(T);
	cout << endl;
	return 0;
}
