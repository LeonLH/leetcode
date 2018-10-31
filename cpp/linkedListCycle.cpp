#include<iostream>
#include<map>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};
// Using map 16ms
class Solution1{
public:
	bool hasCycle(ListNode* head){
		map<ListNode*, int> M;
		for(ListNode* p = head; p; p = p->next){
			pair<ListNode*, int> pair(p, p->val);
			std::pair<map<ListNode*, int>::iterator, bool> res = M.insert(pair);
			if(res.second == false)
				return true;
		}
		return false;
	}
};
// Using a fast and slow pointer, if has a cycle, both pointers 
// will loop in the cycle and they will meet inevitable.
class Solution{
public:
	bool hasCycle(ListNode* head){
		if(!head) return false;
		if(!head->next) return false;

		ListNode* fast = head;
		ListNode* slow = head;
		while(!fast && !slow && !fast->next){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast)
				return true;
		}
		return false;
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
	int l1[] = {32, 14, 23, 67, 87};
	ListNode* head1 = createList(l1, sizeof(l1)/sizeof(int));
	return 0;
}
