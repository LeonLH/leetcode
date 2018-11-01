#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}

};

// iteratively 4ms
class Solution{
public:
	ListNode* reverseList(ListNode* head){
		if(!head)
			return NULL;
		ListNode* p = head->next;
		ListNode* prev = head;

		while(p){
			ListNode* next = p->next;
			p->next = prev;
			prev = p;
			p = next;
		}
		head->next = NULL;
		return prev;

	}
};

// recursively
class Solution1{
public:
	ListNode* reverseList(ListNode* head){
		if(!head) return NULL;
		if(!head->next) return head;
		ListNode* nhead = reverseList(head->next);
		ListNode* p = nhead;
		while(p->next) p = p->next;
		p->next = head;
		head->next = NULL;
		return nhead;
	}
};

ListNode* createList(int A[], int n){
	if(n < 1)
		return NULL;
	ListNode* dummy = new ListNode(0);
	ListNode* p = dummy;
	for(int i = 0; i < n; i++){
		p->next = new ListNode(A[i]);
		p = p->next;
	}
	return dummy->next;
}

void printList(ListNode* head){
	for(ListNode* p = head; p; p = p->next)
		cout << p->val << " ";
	cout << endl;
}

int main(){
	int A[] = {32, 34, 53, 13, 77, 87};
	int n = sizeof(A)/sizeof(int);
	ListNode* p = createList(A, n);
	printList(p);
	Solution S;
	ListNode* rev = S.reverseList(p);
	printList(rev);

}
