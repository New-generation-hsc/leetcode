#include <iostream>
#include <climits>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        while(l1 != NULL || l2 != NULL){
        	ListNode* node = NULL;
        	int w = l1 ? l1->val : INT_MAX;
        	int v = l2 ? l2->val : INT_MAX;
        	if(w <= v){
        		node = l1;
        		l1 = l1->next;
        	}else{
        		node = l2;
        		l2 = l2->next;
        	}
        	tmp->next = node;
        	tmp = node;
        }
        return head->next;
    }
};

int main(int argc, char const *argv[])
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	l1->next = l2;
	ListNode* l4 = new ListNode(4);
	l2->next = l4;

	ListNode* l11 = new ListNode(1);
	ListNode* l3 = new ListNode(3);
	l11->next = l3;
	ListNode* l44 = new ListNode(4);
	l3->next = l44;

	Solution s;
	ListNode* root = s.mergeTwoLists(l1, l11);
	while(root != NULL){
		cout << root->val << endl;
		root = root->next;
	}
	return 0;
}