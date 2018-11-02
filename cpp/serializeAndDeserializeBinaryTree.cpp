#include<utility>
#include<sstream>
#include<queue>
#include<vector>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){}
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int searchInorderPos(int in[], int key, int n);
void adjustStackTop(stack<TreeNode*> &S, vector<pair<int, bool>> &inV, int in[]);
TreeNode* createTree(int in[], int pre[], int n);
void printInorder(TreeNode* T);
void printPreorder(TreeNode* T);

class Codec{
public:
	// Traversal method
	void serializeHelper2(TreeNode* T, vector<TreeNode*> &v){
		if(!T){
			v.push_back(NULL);
			return;
		}
		stack<TreeNode*> S;
		TreeNode* p = T;
		S.push(T);
		while(!S.empty()){
			p = S.top();
			S.pop();
			v.push_back(p);
			if(!p)
				continue;
			S.push(p->right);
			S.push(p->left);
		}
		
	}

	// wrong method
	void serializeHelper1(TreeNode* T, vector<TreeNode*> &v){
		if(!T){
			v.push_back(NULL);
			return;
		}
		stack<TreeNode*> S;
		TreeNode* p = T;
		S.push(T);
		while(!S.empty()){
			p = S.top();
			S.pop();
			v.push_back(p);
			if(p->right)
				S.push(p->right);
			else
				v.push_back(NULL);
			if(p->left)
				S.push(p->left);
			else
				v.push_back(NULL);
		}
		
	}

	// Recursive method
	void serializeHelper(TreeNode* T, vector<TreeNode*> &v){
		if(T == NULL)
			v.push_back(NULL);
		else{
			v.push_back(T);
			serializeHelper(T->left, v);
			serializeHelper(T->right, v);
		}
	}

	string serialize(TreeNode* root){
		string res;
		vector<TreeNode*> v;
		serializeHelper2(root, v);
		for(int i = 0; (unsigned)i < v.size(); ++i)
			res += (v[i] == NULL ? "#" : to_string(v[i]->val)) +" ";
		return res;
	}

	TreeNode* deserializeHelper(vector<TreeNode*> &v, int &index){

		if((unsigned)index >= v.size()) return NULL;
		TreeNode* root = v[index++];
		if(root){
			root->left  = deserializeHelper(v, index);
			root->right = deserializeHelper(v, index);
		}
		return root;
	}

	void split(const string &s, char delim, vector<TreeNode*> &elems){
		stringstream ss(s);
		string item;
		while(getline(ss, item, delim)){
			TreeNode* node = (item == "#" ? NULL : new TreeNode(stoi(item)));
			elems.push_back(node);
		}
	}

	TreeNode* deserialize(string data){
		vector<TreeNode*> v;
		split(data, ' ', v);
		int index = 0;
		return deserializeHelper(v, index);
	}
};

int main(){
	int in[]  = {30, 56, 18, 62, 34, 25, 23};
	int pre[] = {34, 56, 30, 62, 18, 23, 25};
	int n = sizeof(in)/sizeof(int);
	TreeNode* T = createTree(in, pre, n);
	cout << "in : ";
	printInorder(T);
	cout << endl << "pre: ";
	printPreorder(T);

	Codec C;
	string serializedSTR = C.serialize(T);
	cout << serializedSTR << endl;
	TreeNode* p = C.deserialize(serializedSTR);
	cout << "After deserialize, inorder:\t";
	printInorder(p);
	cout << endl << "After deserialize, preorder:\t";
	printPreorder(p);

	return 0;
}

// It works, But it's too slow that it cuases Time Limit Exceeded.
class Codec1{
public:
	string serialize(TreeNode* root){
		if(!root)
			return "$#";
		// levelorder
		string res;
		TreeNode* p = root;
		queue<TreeNode*> Q;
		Q.push(p);
		while(!Q.empty()){
			p = Q.front();
			Q.pop();
			res += to_string(p->val);
			if(p->left)
				Q.push(p->left);
			else
				res += "$";
			if(p->right)
				Q.push(p->right);
			else
				res += "#";
			res += " ";
		}
		return res;
	}

	TreeNode* strToTnode(string str){	// "25$#"--->TreeNode(25);
		while(str.back() == '#' || str.back() == '$')
			str.pop_back();
		TreeNode* p = new TreeNode(stoi(str));
		return p;
	}	

	vector<pair<string, TreeNode*>> buildVec(string data){
		vector<pair<string, TreeNode*>> V;
		string str;
		TreeNode* p = NULL;
		stringstream ss;
		ss.str(data);
		while(getline(ss, str, ' ')){
			p = strToTnode(str);
			pair<string, TreeNode*> tmp;
			tmp.first = str;
			tmp.second = p;
			V.push_back(tmp);
		}
		return V;
	}

	int locatPos(TreeNode* p, vector<pair<string, TreeNode*>> V){
		for(unsigned int i = 0; i < V.size(); ++i)
			if(p == V[i].second)
				return i;
		return -1;
	}

	int typeOfSubtree(string str){
		char c = str.back();
		if(c != '#' && c != '$')
			return 3;
		else if(c == '$')
			return 2;
		else{				// c == '#'
			str.pop_back();
			c = str.back();
			if(c == '$')
				return 0;
			else
				return 1;
		}

	}

	TreeNode* deserialize(string data){
		if(data == "$#")
			return NULL;
		vector<pair<string, TreeNode*>> V = buildVec(data);
		queue<TreeNode*> Q;
		Q.push(V[0].second);
		int i = 0;
		while(!Q.empty()){
			TreeNode* p = Q.front();
			Q.pop();
			int pos = locatPos(p, V);
			int type = typeOfSubtree(V[pos].first);
			if(type == 1){				// Left only
				i++;
				p->left = V[i].second;
				Q.push(p->left);
			}
			else if(type == 2){			// Right only
				i++;
				p->right = V[i].second;
				Q.push(p->right);
			}	
			else if(type == 3){			// Both
				i++;
				p->left = V[i].second;
				Q.push(p->left);
				i++;
				p->right = V[i].second;
				Q.push(p->right);
			}
			else if(type == 0)			// Both NULL
				;
		}
		return V[0].second;
	}
};

int searchInorderPos(int in[], int key, int n){
	for(int i = 0; i < n; i++){
		if(key == in[i])
			return i;
	}
	return -1;
}

void adjustStackTop(stack<TreeNode*> &S, vector<pair<int, bool>> &inV, int in[]){
	while(!S.empty()){
		TreeNode* p = S.top();
		int n = inV.size();
		int idx = searchInorderPos(in, p->val, n);
		if((idx == 0 && !inV[1].second) || (idx == n-1 && !inV[n-2].second) || (!inV[idx-1].second && !inV[idx+1].second))
			S.pop();
		else
			break;
	}
}

TreeNode* createTree(int in[], int pre[], int n){
	if(!n)
		return NULL;
	vector< pair<int, bool> > inV;
	for(int i = 0; i < n; ++i)
		inV.push_back(pair<int, bool> (in[i], true));	

	stack<TreeNode*> S;

	TreeNode* T = new TreeNode(pre[0]);
	int tmp = searchInorderPos(in, pre[0], n);
	inV[tmp].second = false;
	TreeNode* p = T;
	S.push(p);
	int i = 1;
	while(!S.empty()){
		TreeNode* pnew = new TreeNode(pre[i]);
		int idx = searchInorderPos(in, pre[i], n);
		p = S.top();
		int topIdx = searchInorderPos(in, p->val, n);

		if(idx < topIdx){
			p->left = pnew;
			S.push(pnew);
			inV[idx].second = false;
			adjustStackTop(S, inV, in);
		}
		else{
			p->right = pnew;
			S.push(pnew);
			inV[idx].second = false;
			adjustStackTop(S, inV, in);
		}
		++i;
	}
	return T;
}

void printInorder(TreeNode* T){
	TreeNode* p = T;
	stack<TreeNode*> S;
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

void printPreorder(TreeNode* T){
	if(!T)
		return;
	stack<TreeNode*> S;
	S.push(T);
	TreeNode* p = NULL;
	while(!S.empty()){
		p = S.top();
		S.pop();
		cout << p->val << " ";
		if(p->right)
			S.push(p->right);
		if(p->left)
			S.push(p->left);
	}
	cout << endl;
}

