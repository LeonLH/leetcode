#include<iostream>
#include<map>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

// 24ms 
class Solution{
public:
	ListNode* getIntersectionNode(ListNode* l1, ListNode* l2){
		ListNode* a = l1, * b = l2;
		while(a != b){
			a = a ? a->next : l2;
			b = b ? b->next : l1; 
		}
		return a;
	}
};

// 56ms Using map
class Solution1{
public:
	ListNode* getIntersectionNode(ListNode* l1, ListNode* l2){
		map<ListNode*, int> M;
		for(ListNode* p = l1; p; p = p->next)
			M.insert(pair<ListNode*, int> (p, p->val));
		
		for(ListNode* p = l2; p; p = p->next){
			std::pair<map<ListNode*, int>::iterator, bool> res = M.insert(pair<ListNode*, int> (p, p->val));
			if(res.second == false)
				return res.first->first;
		}
		return NULL;
	}
};

class Solution2{
public:
	ListNode* getIntersection(ListNode* l1, ListNode* l2){
		ListNode* p = l2;
		while(p->next) p = p->next;
		p->next = l2;

		p = l1;
		while(p){
			if(p == l2)
				return NULL;
		}
		return NULL;

	}
};

ListNode* createList(int A[], int n){
	if(n < 1)
		return NULL;
	ListNode* head = new ListNode(A[0]);
	ListNode* p = head;
	for(int i = 1; i < n; i++){
		p->next = new ListNode(A[i]);
		p = p->next;
	}
	return head;
}

void printList(ListNode* head){
	for(ListNode* p = head; p; p = p->next){
		cout << p->val << " ";
	}
	cout << endl;

}

int main(){
	int l1[] = {14, 23, 32, 67, 87};
	int l2[] = {45, 66, 21, 32, 67, 87};
	return 0;
}
