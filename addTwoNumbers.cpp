#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
class List{
	
public:
	ListNode *head;
	ListNode *tail;
	ListNode* addTail(ListNode* node){
		if(head == NULL){
			ListNode* newNode = new ListNode(0);
			newNode->val = node->val;
			newNode->next = NULL;
			head = newNode;
			tail = newNode;
		}
		else{
			ListNode* newNode = new ListNode(0);
			newNode->val = node->val;
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
		}
		return head;
	}
};

class Solution1 {
public:		//brutle force
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1,*p2 = l2;

		//将两个链表变得一样长，短的在尾部追加0
		while(p1->next || p2->next)
		{
			if(!p1->next)
			{
				p1->next = new ListNode(0);
				p1 = p1 ->next;
			}
			else
				p1 = p1->next;
			if(!p2->next)
			{
				p2->next = new ListNode(0);
				p2 = p2 ->next;
			}
			else
				p2 = p2->next;
		}

		//将l1 l2每一位相加，存到新列表pRes中
		p1 = l1,p2 = l2;
		ListNode *pRes = new ListNode(0),*p;
		p = pRes; 
		while(p1)
		{			
			p->val = p1->val + p2->val;
			if(p1->next)
				p -> next = new ListNode(0);
			p = p-> next;
			p1 = p1 -> next;
			p2 = p2 -> next;			
		}

		//将每一位进的1加到后一位上
		p = pRes;
		while(p->next)	//必须要p->next不为空才能赋值
		{
			if(p->val >= 10)
			{
				p->val %= 10;
				p->next->val += 1;
			}
			p = p->next;
		}
		if(p->val >= 10)
		{
			p->val %= 10;
			p->next = new ListNode(1);
		}
		return pRes;
	}
};


class Solution{
//0.检验输入是否正确，如果有字母/符号等非法输入，则返回错误信息，checkInput();
//1.输入的是字符串，修正字符串左右两端的空格,trimString();
//2.把string中的每个元素存入ListNode中,stringIntoList();
//3.把两条List对应位的元素相加得到addList，遍历List，如果大于10则给下一位加一；
public:
	list<int> addTwoNumbers(string& str1, string& str2){
		if(!checkInput(str1)||!checkInput(str2))		//0.checkInput
			cout << "Illegel Input" << endl;
		trimString(str1);trimString(str2);			//1.trimString
		list<int> l1 = stringIntoList(str1);
		list<int> l2 = stringIntoList(str2);
		
		list<int> addList; 							//2.addList
		list<int>::iterator it1 = l1.begin();
		list<int>::iterator it2 = l2.begin();
		for(; it1!=l1.end()&&it2!=l2.end(); it1++,it2++){
			int tempAdd = *it1+*it2;
			addList.push_back(tempAdd);
		}
		if(it1==l1.end())
			for(;it2!=l2.end();it2++)
				addList.push_back(*it2);
		if(it2==l2.end())
			for(;it1!=l1.end();it1++)
				addList.push_back(*it1);
		for(list<int>::iterator it = addList.begin(); it!=addList.end(); it++){
			if(*it>=10){
				*it %= 10;
				++it;
				if(it==addList.end())
					addList.push_back(0);
				int tmp = *it;
				//addList.emplace(it,++tmp);
				*it = ++tmp;
				--it;
			}
			
		}
		return addList;
	}
	int checkInput(string str){
		for(std::string::iterator it=str.begin(); it != str.end(); ++it){
			if(*it!=32 && (*it>57 ||*it<48))
				return 0;
		}	
		return 1;
	}	
	void trimString(string& l){
		for(;l.back()==' ';)
			l.pop_back();
		for(;l.front()==' ';)
			l.erase(l.begin());
	}
	list<int> stringIntoList(string str){
		list<int> l;
		for(int i=str.length()-1;  i>=0; i--){
			char c = str[i];
			int digit_dec = atoi(&c);
			//ListNode* newNode = new ListNode(0);
			//newNode->val = digit_dec;
			l.push_back(digit_dec);
			
		}
		return l;
	}
//	void printList(list<int> &l){
//		std::list<int>::iterator it = l.end();
//		--it;
//		for(; it!=l.begin(); --it)
//			cout<< *it ;
//		cout << *it;
//		cout << endl;
//	}
};
int main(){
	string l1("342  "), l2("  67");
//	cout << "please input l1"<<endl;
//	cin.clear();
//	getline(cin, l1);
//	cout << "please input l2"<<endl;
//	cin.clear();
//	getline(cin, l2);
		
	Solution A;
	//A.trimString(l1);
	A.checkInput(l1);
	list<int> resList = A.addTwoNumbers(l1,l2);
	return 0;
}
































