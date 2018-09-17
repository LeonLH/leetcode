#include"LIST.cpp"
//Definition for singly-linked list.

class Solution {	//don't destroy original list
	//Notice: consider one of list is blank list
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *p1,*p2;
		p1 = l1;
		p2 = l2;
		ListNode *pNewHead = nullptr;
		ListNode *pNew = pNewHead;
		while(p1&&p2){
			if(p1->val<=p2->val){
				if(!pNewHead){
					pNewHead = new ListNode(p1->val);
					pNew = pNewHead;
				}
				else{
					pNew->next = new ListNode(p1->val);
					pNew = pNew->next;
				}
				p1 = p1->next;
			}
			else{
				if(!pNewHead){
					pNewHead = new ListNode(p2->val);
					pNew = pNewHead;
				}
				else{
					pNew->next = new ListNode(p2->val);
					pNew = pNew->next;
				}
				p2 = p2->next;
			}
		}
		if(!p1){
			for(; p2!=0; p2=p2->next){            
                if(!pNewHead){
                    pNewHead = new ListNode(p2->val);
                    pNew = pNewHead;
                }
                else{
                    pNew->next = new ListNode(p2->val);
				    pNew = pNew->next;
                }
			}
        }
		if(!p2)
			for(; p1!=0; p1=p1->next){
				if(!pNewHead){
                    pNewHead = new ListNode(p1->val);
                    pNew = pNewHead;
                }
                else{
                    pNew->next = new ListNode(p1->val);
				    pNew = pNew->next;
                }
			}
		return pNewHead;
    }
};
class Solution1 {		//destroy original list
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *p1,*p2;
		p1 = l1;
		p2 = l2;
		ListNode *pNewHead = nullptr;
		ListNode *pNew = pNewHead;
		while(p1&&p2){
			if(p1->val<=p2->val){
				if(!pNewHead){
					pNewHead = p1;
					pNew = pNewHead;
				}
				else{
					pNew->next = p1;
					pNew = pNew->next;
				}
				p1 = p1->next;
			}
			else{
				if(!pNewHead){
					pNewHead = p2;
					pNew = pNewHead;
				}
				else{
					pNew->next = p2;
					pNew = pNew->next;
				}
				p2 = p2->next;
			}
		}
		if(!p1)
			for(; p2!=0; p2=p2->next){
				pNew->next = p2;
				pNew = pNew->next;
			}
		if(!p2)
			for(; p1!=0; p1=p1->next){
				pNew->next = p1;
				pNew = pNew->next;
			}
		return pNewHead;
    }
};
int main(){
	int array1[] = {1, 2, 7, 29};
	int array2[] = {1, 4, 5, 23, 67};
	ListNode *pl1, *pl2;
	ListNode l1, l2;
	pl1 = l1.inputList(array1, sizeof(array1)/sizeof(int));
	pl2 = l2.inputList(array2, sizeof(array2)/sizeof(int));
	l1.outputList(pl1);
	l1.outputList(pl2);
	Solution A;
	ListNode *pNew = A.mergeTwoLists(pl1, pl2);
	pNew->outputList(pNew);

	Solution B;
	pNew = B.mergeTwoLists(pl1, pl2);
	pNew->outputList(pNew);
	l1.deleteList(pl1);
	l2.deleteList(pl2);
	pNew->deleteList(pNew);
	return 0;
}
