/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/add-two-numbers/description/
 * runtime: 0ms
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head, int x) {
        int carry = 0;
        ListNode* p1 = l1, *p2 = l2;
        ListNode *dummyH = new ListNode(0);
        ListNode *cur = dummyH;
        while(p1 != nullptr || p2 != nullptr || carry) {
            int v1 = (p1 != nullptr) ? p1->val : 0;
            int v2 = (p2 != nullptr) ? p2->val : 0;
            
            int val = v1+v2+carry;
            if(val >= 10) {
                carry = 1;
                cur->next = new ListNode(val-10, nullptr);
            } else {
                carry = 0;
                cur->next = new ListNode(val, nullptr);
            }
            p1 = (p1 != nullptr) ? p1->next : p1; 
            p2 = (p2 != nullptr) ? p2->next : p2; 
            cur = cur->next;
        }

        ListNode* ret = dummyH->next;
        delete dummyH;
        return ret;
    }
};