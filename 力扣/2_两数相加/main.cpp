#include <list>
#include <vector>
#include <iostream>

using namespace std;

// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.

// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// O(n)
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = new ListNode(0);
        ListNode* p = pHead;
        bool flag = 0;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 == NULL){
                l1 = new ListNode(0);
            }
            if(l2 == NULL){
                l2 = new ListNode(0);
            }
            int tempInt = l1->val + l2->val + flag;
            if(tempInt >= 10){
                tempInt %= 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            ListNode* tempNode = new ListNode(tempInt);
            p->next = tempNode;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(flag){
            p->next = new ListNode(1);
        }
        return pHead->next;
    }
};

// 3/4 * n 这个代码太丑了
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = new ListNode(0);
        ListNode* p = pHead;
        bool flag = 0;
        while(l1 != NULL && l2 != NULL)
        {
            int tempInt = l1->val + l2->val + flag;
            if(tempInt >= 10){
                tempInt %= 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            ListNode* tempNode = new ListNode(tempInt);
            p->next = tempNode;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 == NULL){
            p->next = l2;
        }
        else{
            p->next = l1;
        }

        if(p->next == NULL && flag == 1)
        {
            p->next = new ListNode(1);
            return pHead->next;
        }

        p = p->next;
        while(flag == 1 )
        {
            p->val += 1;
            if(p->val == 10)
            {
                p->val = 0;
                flag = 1;
                if(p->next)
                {
                    p = p->next;
                }
                else
                {
                    p->next = new ListNode(1);
                    break;
                }
            }
            else
            {
                flag = 0;
            }
        }
        return pHead->next;
    }
};

// 这个是参考代码，我的代码写不太优雅
class Solution3 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(-1),*curr=dummy;
        int carry=0;
        while(l1 || l2 || carry!=0){
            int val1=(l1!=NULL?l1->val:0);
            if(l1!=NULL){
                l1=l1->next;
            }
            int val2=(l2!=NULL?l2->val:0);
            if(l2!=NULL){
                l2=l2->next;
            }
            int total=val1+val2+carry;
            int val=total%10;
            carry=total/10;
            curr->next=new ListNode(val);
            curr=curr->next;
        }
        return dummy->next;
    }
};

// solution1优雅化
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = new ListNode(0);
        ListNode* p = pHead;
        bool flag = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int val1 = (l1 != NULL)? l1->val : 0;
            int val2 = (l2 != NULL)? l2->val : 0;

            int tempInt = val1 + val2 + flag;
            if(tempInt >= 10){
                tempInt %= 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            ListNode* tempNode = new ListNode(tempInt);
            p->next = tempNode;
            p = p->next;
            l1 = (l1 != NULL)? l1->next : NULL;
            l2 = (l2 != NULL)? l2->next : NULL;
        }
        if(flag){
            p->next = new ListNode(1);
        }
        return pHead->next;
    }
};


void printList(ListNode* node){

    while(node)
    {
        cout << node->val << " " ;
        node = node->next;
    }
    cout << endl;
}

ListNode* buildList(vector<int> myints_1){
    ListNode* pHead = new ListNode(0);
    ListNode* p = pHead;
    for(auto n : myints_1)
    {
        ListNode* tmp_node = new ListNode(n);
        p->next = tmp_node;
        p = p->next;
    }
    return pHead->next;
}

int main(){
    vector<int> myints_1 = {9,9,9,9,9,9,9};
    vector<int> myints_2 = {9,9,9,9};
    ListNode* l1 = buildList(myints_1);
    ListNode* l2 = buildList(myints_2);

    // printList(l1);
    // printList(l2);

    Solution A;
    ListNode* ret = A.addTwoNumbers(l1, l2);
    printList(ret);
    

    return 0;
}