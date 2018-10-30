#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
	ListNode(){}
};
// There is a good way: 
// 	0. First separate
// Maybe the mergeSort is a good idea; 

// Mergesort


class Solution{
public:
	ListNode* sortList(ListNode* head){
		if(head == NULL || head->next == NULL)
			return head;

		ListNode* p1 = head, * p2 = head->next;
		while(p2 && p2->next){
			p1 = p1->next;
			p2 = p2->next->next;
		}
		p2 = p1->next;
		p1->next = NULL;
		return mergerTwoList(sortList(head), sortList(p2));
	}

	ListNode* mergerTwoList(ListNode* head1, ListNode* head2){
		ListNode* p1 = head1, * p2 = head2;
		static ListNode dummy(0);
		ListNode* tail = &dummy;

		while(p1 && p2){
			if(p1->val <= p2->val){
				tail->next = p1;
				p1 = p1->next;
				tail = tail->next;
			}
			else{
				tail->next = p2;
				p2 = p2->next;
				tail = tail->next;
			}
		}
		if(p1)
			tail->next = p1;
		if(p2)
			tail->next = p2;
		return dummy.next;
	}
};

class Solution3{
public:
	void mergeCore(ListNode* low, ListNode* mid, ListNode* high){
		ListNode* p1 = low, * p2 = mid->next;
		ListNode* list = new ListNode(0);
		ListNode* p = list;
		while(p1 != mid->next && p2 != high->next){
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
		// if(p1 != mid ) p->next = p1;
		// if(p2 != high) p->next = p2;
		while(p1 != mid->next){
			p->next = p1;
			p1 = p1->next;
			p = p->next;
		}
		high = p;
		while(p2 != high->next){
			p->next = p2;
			p2 = p2->next;
			p = p->next;
		}
		low = list->next;

	}
	void mergeSort(ListNode* low, ListNode* high){
		if(low != high){
			ListNode* p1 = low;
			ListNode* p2 = low;
			while(p2 != high && p2->next != high){
				p1 = p1->next;
				p2 = p2->next->next;
			}
			ListNode* mid = p1;
		
			mergeSort(low, mid);
			mergeSort(mid->next, high);
			mergeCore(low, mid, high);
		}
	}

	
	ListNode* sortList(ListNode* head){
		ListNode* p = head;
		while(p->next) p = p->next;
		ListNode* end = p;
		mergeSort(head, end);
		return head;
	}
};


// Bubblesort
class Solution1{
public:
	ListNode* sortList(ListNode* head){
		ListNode* p = head;
		int n = 0;
		while(p){
			++n;
			p = p->next;
		}
		p = head;
		for(int i = 1; i < n; ++i){
			p = head;
			ListNode* prev = NULL;
			for(int step = n-i; step >= 0; --step){
				if(prev && prev->val > p->val){
					int tmp = prev->val;
					prev->val = p->val;
					p->val = tmp;
				}
				prev = p;
				p = p->next;
			}
		}

		return head;
	}
};	// bubbleSort Time Limit Exceeded

// quickSort 
class Solution2{
public:
	int partition(vector<int> &v, int low, int high){
		int pivot;
		pivot = v[low];
		while(low < high){
			while(low < high && v[high] >= pivot)
				--high;
			v[low] = v[high];
			while(low < high && v[low] <= pivot)
				++low;
			v[high] = v[low];
		}
		v[low] = pivot;
		return low;
	}
	void quickSort(vector<int> &v, int low, int high){
		if(low < high){
			int pivotpos = partition(v, low, high);
			quickSort(v, low, pivotpos-1);
			quickSort(v, pivotpos+1, high);
		}
	}// 144ms
	ListNode* sortList(ListNode* head){
		vector<int> v;
		for(ListNode* p = head; p != NULL; p = p->next)
			v.push_back(p->val);
		
		quickSort(v, 0, v.size()-1);
		
		ListNode* p = head;
		for(int i = 0; (unsigned)i < v.size(); ++i){
			p->val = v[i];
			p = p->next;	
		}
		return head;
	}
};
/************************** Utilities ******************************/
void printList(ListNode* L){
	for(ListNode* p = L; p != NULL; p = p->next){
		cout << p->val << " ";
	}
	cout << endl;
}

int main(){
	ListNode node1(4);
	ListNode node2(2);
	ListNode node3(1);
	ListNode node4(3);
//	ListNode node5(-3);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	//node4.next = &node5;
	Solution A;
	ListNode* head = A.sortList(&node1);
	printList(head);
	return 0;
}
