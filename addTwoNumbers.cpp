#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(l1 != NULL || l2 != NULL || carry){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head->next;
    }
};

int main(){
    ListNode* a1 = new ListNode(2);
    ListNode* a2 = new ListNode(4);
    a1->next = a2;
    ListNode* a3 = new ListNode(3);
    a2->next = a3;

    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    b1->next = b2;
    ListNode* b3 = new ListNode(4);
    b2->next = b3;

    Solution s;

    ListNode* ret = s.addTwoNumbers(a1, b1);
    while(ret != NULL){
        cout << ret->val << endl;
        ret = ret->next;
    }

    return 0;
}
