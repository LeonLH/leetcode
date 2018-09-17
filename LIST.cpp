#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr){}
	ListNode(){};
	ListNode* inputList(int *pArray, int arrayLen);
	void outputList(ListNode *pHead);
	void deleteList(ListNode *pHead);
};

ListNode* ListNode::inputList(int *pArray, int arrayLen){
	ListNode *pHead = nullptr;
	ListNode *pTail = pHead;
	int listLen = 0;
	for(int i=0; i<arrayLen; ++i){
		ListNode *p = new ListNode(0);
		p->val = *pArray;
		if(!pHead){
			pHead = p;
			pTail = pHead;
		}
		pTail->next = p;
		pTail = p;
		pArray++;
		listLen++;
	}
	return pHead;
}
void ListNode::outputList(ListNode *pHead){
	ListNode *p = pHead;
	if(!pHead)
		return;
	while(p->next){
		cout << p->val << "->" ;
		p = p->next;
	};
	cout << p->val << endl;
}
void ListNode::deleteList(ListNode *pHead){
	ListNode *p = pHead;
	while(p->next){
		ListNode *pPre = p;
		p = p->next;
		delete pPre;
	}
	delete p;
}
