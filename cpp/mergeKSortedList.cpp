#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}

};
// 16ms 
// Linked as one linked list, and then use mergesort to sort the big list.
class Solution1{
public:
	void mergeTwoList(ListNode* &p1, ListNode* p2){
		static ListNode* dummy = new ListNode(0);
		ListNode* p = dummy;
		while(p1 && p2){
			if(p1->val <= p2->val){
				p->next = p1;
				p1 = p1->next;
				p = p->next;
			}
			else{
				p->next = p2;
				p2 = p2->next;
				p = p->next;
			}
		}
		if(p1) p->next = p1;
		if(p2) p->next = p2;
		p1 = dummy->next;
	}

	void sortList(ListNode* &head){
		if(head && head->next){
			ListNode* p1 = head;
			ListNode* p2 = head;
			while(p2->next && p2->next->next){
				p1 = p1->next;
				p2 = p2->next->next;
			}
			p2 = p1->next;
			p1->next = NULL;
			p1 = head;

			sortList(p1);
			sortList(p2);
			mergeTwoList(p1, p2);
			head = p1;
		}
	}

	// Soppose we have three lists: list1, list2, list3
	// First, we just link these lists end to end to a long linked list;
	// Second, we use mergeSort to sort the long list.
	ListNode* mergeKLists(vector<ListNode*>& lists){
		if(lists.size() < 1)
			return NULL;
		if(lists.size() == 1){
			sortList(lists[0]);
			return lists[0];
		}

		vector<ListNode*> tailv(lists.size(), NULL);
		if(lists == tailv)
			return NULL;
		ListNode* dummy = new ListNode(0);
		ListNode* p = dummy;
		for(unsigned int i = 0; i < lists.size(); ++i){
			if(!lists[i])
				continue;
			p->next = lists[i];
			p = p->next;
			while(p->next)
				p = p->next;
		}
		p = dummy->next;
		sortList(p);
		return p;
	}
};

// 384ms merge many list at the same time. 
class Solution{
public:
	void mergeTwoList(ListNode* &p1, ListNode* p2){
		static ListNode* dummy = new ListNode(0);
		ListNode* p = dummy;
		while(p1 && p2){
			if(p1->val <= p2->val){
				p->next = p1;
				p1 = p1->next;
				p = p->next;
			}
			else{
				p->next = p2;
				p2 = p2->next;
				p = p->next;
			}
		}
		if(p1) p->next = p1;
		if(p2) p->next = p2;
		p1 = dummy->next;
	}

	void sortList(ListNode* &head){
		if(head && head->next){
			ListNode* p1 = head;
			ListNode* p2 = head;
			while(p2->next && p2->next->next){
				p1 = p1->next;
				p2 = p2->next->next;
			}
			p2 = p1->next;
			p1->next = NULL;
			p1 = head;

			sortList(p1);
			sortList(p2);
			mergeTwoList(p1, p2);
			head = p1;
		}
	}


	int currvMinIndex(vector<ListNode*> currv){
		if(!currv.size())
			return -1;
		if(currv.size() == 1)
			return 0;
		int i;
		for(i = 0; (unsigned)i < currv.size(); ++i){
			if(currv[i])
				break;	
		}
		int minindex = i;
		int min = currv[i]->val;
		for(unsigned int i = 0; i < currv.size(); ++i){
			if(!currv[i])
				continue;
			if(currv[i]->val < min){
				minindex = i;
				min = currv[i]->val;
			}
		}
		return minindex;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists){
		if(lists.size() < 1)
			return NULL;
		if(lists.size() == 1){
			sortList(lists[0]);
			return lists[0];
		}

		vector<ListNode*> tailv(lists.size(), NULL);
		if(lists == tailv)
			return NULL;
		for(unsigned int i = 0; i < lists.size(); ++i)
			sortList(lists[i]);
		vector<ListNode*> currv;
		currv = lists;

		static ListNode* dummy = new ListNode(0);
		ListNode* p = dummy;
		while(currv != tailv){
			int i = currvMinIndex(currv);
			p->next = currv[i];
			p = p->next;
			currv[i] = currv[i]->next;

		}
		return dummy->next;
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
	int l1[] = {93, 49, 5};
	int l2[] = {34, 56, 14, 56};
	int l3[] = {32, 14, 23, 67, 87};
	ListNode* head1 = createList(l1, sizeof(l1)/sizeof(int));
	ListNode* head2 = createList(l2, sizeof(l2)/sizeof(int));
	ListNode* head3 = createList(l3, sizeof(l3)/sizeof(int));
	vector<ListNode*> V = {head1, head2, head3};
	Solution1 A;
//	A.sortList(head1);
//	A.sortList(head2);
//	A.sortList(head3);
//	printList(head1);
//	printList(head2);
//	printList(head3);

	ListNode* res = A.mergeKLists(V);
	printList(res);
	
	return 0;
}
