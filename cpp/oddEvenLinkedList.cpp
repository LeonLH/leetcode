#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
	
};
// every iterator have to steps. 12ms 
class Solution{
public:
	ListNode* oddEvenList(ListNode* head){
		if(!head)
			return NULL;
		if(!head->next)
			return head;

		ListNode* p = head;
		ListNode* psec = head->next;
		ListNode* fir = NULL, * sec = NULL;
		while(p){
			fir = p;
			sec = p->next;

			if(sec){	// double
				fir->next = sec->next;
				if(sec->next)
					sec->next = sec->next->next;
				else
					sec->next = NULL;
			}
			else		// single
				fir->next = NULL;
			p = fir->next;
		}
		p = head;
		while(p->next) p = p->next;
		p->next = psec;
		return head;
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
	int A[] = {32, 34, 53, 13, 77, 87, 93};
	int n = sizeof(A)/sizeof(int);
	ListNode* p = createList(A, n);
	printList(p);
	Solution S;
	ListNode* rev = S.oddEvenList(p);
	printList(rev);

}
