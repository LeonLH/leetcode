#include<iostream>

using namespace std;

struct RandomListNode{
	int label;
	RandomListNode* next, * random;
	RandomListNode(int x): label(x), next(NULL), random(NULL) {}
};
// Be careful don't forget to recover the oringnal list
class Solution{
public:
	RandomListNode* copyRandomList(RandomListNode* head){
		if(!head)
			return NULL;
		for(RandomListNode* p = head; p; p = p->next){
			RandomListNode* pn = p->next;
			p->next = new RandomListNode(p->label);
			p = p->next;
			p->next = pn;
		}
		for(RandomListNode* p = head; p ; p = p->next->next){
			if(!p->random)
				p->next->random = NULL;
			else
				p->next->random = p->random->next;
		}
		RandomListNode* p = head;
		RandomListNode* pnew = head->next;
		while(p && p->next->next){
			RandomListNode* tmp = p->next;
			p->next = tmp->next;
			tmp->next = tmp->next->next;
			p = p->next;
		}
		p->next = NULL;
		return pnew;
	}
};

RandomListNode* createList(int A[], int n){
	if(n < 1)
		return NULL;
	RandomListNode* head = new RandomListNode(A[0]);
	RandomListNode* p = head;
	for(int i = 1; i < n; i++){
		p->next = new RandomListNode(A[i]);
		p = p->next;
	}
	return head;
}

void printList(RandomListNode* head){
	for(RandomListNode* p = head; p; p = p->next){
		cout << p << ":" << p->label << "  ";
	}
	cout << endl;

}

int main(){
	int l3[] = {32, 14, 23, 67, 87};
	RandomListNode* head3 = createList(l3, sizeof(l3)/sizeof(int));
	printList(head3);
	Solution A;
	RandomListNode* copy = A.copyRandomList(head3);
	printList(head3);
	printList(copy);
	return 0;
}
