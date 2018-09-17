#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr){}
};

class Solution1{
//0.把头结点存上链表的长度；
//1.先遍历到尾节点，得到链表长度，检查输入N是否合法	//checkInput
//2.第一遍遍历的时候把每个节点的地址保存在一个指针数组中，计算所需要访问的数组的下标，找到该节点；
//3.删除节点；
//4.Additional Features: Input linked list, Output linked list;
//5.Delete list
public:
	ListNode* removeNthFromEnd(ListNode *pHead, int n){
		if(n>pHead->val)
			cout  << "N is out of range" << endl;
		int nth = pHead->val-n+1;
		ListNode *p = pHead->next;
		ListNode *pPre = pHead;
		for(int i=1; i<nth; ++i){
			pPre = p;
			p = p->next;
		}
		pPre->next = p->next;
		delete p;
		return pHead;
	}
	ListNode* inputList(int *pArray, int arrayLen){
		ListNode *pHead = new ListNode(0);
		ListNode *pTail = pHead;
		int listLen = 0;
		for(int i=0; i<arrayLen; ++i){
			ListNode *p = new ListNode(0);
			p->val = *pArray;
			pTail->next = p;
			pTail = p;
			pArray++;
			listLen++;
		}
		pHead->val = listLen;		//pHead->val is the length of list
		return pHead;
	}
	void outputList(ListNode *pHead){
		ListNode *p = pHead->next;
		for(; p->next; p=p->next)
			cout << p->val << endl;
		cout << p->val << endl;
	}
	void deleteList(ListNode *pHead){
		ListNode *p = pHead;
		while(p->next){
			ListNode *pPre = p;
			p = p->next;
			delete pPre;
		}
		delete p;
	}
};


class Solution{
//1.先遍历到尾节点，得到链表长度，检查输入N是否合法	//checkInput
//2.第一遍遍历的时候把每个节点的地址保存在一个指针数组中，计算所需要访问的数组的下标，找到该节点；
//3.删除节点；
//4.Additional Features: Input linked list, Output linked list;
//5.Delete list
public:
	ListNode* removeNthFromEnd(ListNode *pHead, int n){
		int nLen = 0;
		if(!pHead)
			return nullptr;
		for(ListNode* p=pHead; p; p=p->next)
			nLen++;
		if(n>nLen)
			cout  << "N is out of range" << endl;
		int nth = nLen-n+1;
		ListNode *p = pHead;
		ListNode *pPre = pHead;
		if(n==nLen){
			pHead = p->next;
			delete p;
			return pHead;
		}
		for(int i=1; i<nth; ++i){
			pPre = p;
			p = p->next;
		}
		if(p->next==nullptr){
			pPre->next = nullptr;
			delete p;
		}
		else{
			pPre->next = p->next;
			delete p;
		}
		return pHead;
	}
	ListNode* inputList(int *pArray, int arrayLen){
		ListNode *pHead = new ListNode(0);
		ListNode *pTail = pHead;
		int listLen = 0;
		for(int i=0; i<arrayLen; ++i){
			ListNode *p = new ListNode(0);
			p->val = *pArray;
			pTail->next = p;
			pTail = p;
			pArray++;
			listLen++;
		}
		pHead->val = listLen;		//pHead->val is the length of list
		return pHead;
	}
	void outputList(ListNode *pHead){
		ListNode *p = pHead->next;
		for(; p->next; p=p->next)
			cout << p->val << endl;
		cout << p->val << endl;
	}
	void deleteList(ListNode *pHead){
		ListNode *p = pHead;
		while(p->next){
			ListNode *pPre = p;
			p = p->next;
			delete pPre;
		}
		delete p;
	}
//Testing code
int main(){
	int inputArray[5] = {1, 2, 3, 4, 5};
	Solution A;
	ListNode *pList = A.inputList(inputArray, sizeof(inputArray)/sizeof(int));
	A.outputList(pList);
	A.removeNthFromEnd(pList, 3);
	A.outputList(pList);
	A.deleteList(pList);
	return 0;
}
};


//Testing code
int main(){
	int inputArray[5] = {1, 2, 3, 4, 5};
	Solution1 A;
	ListNode *pList = A.inputList(inputArray, sizeof(inputArray)/sizeof(int));
	A.outputList(pList);
	A.removeNthFromEnd(pList, 3);
	A.outputList(pList);
	A.deleteList(pList);
	return 0;
}
