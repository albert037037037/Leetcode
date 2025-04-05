/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 * runtime: 0ms
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode* front = dummy, *cur = dummy;
        for(int i=0; i<n; i++) {
            front = front->next;
        }
        while(front != nullptr) {
            front = front->next;
            if(front != nullptr) {
                cur = cur->next;
            } else {
                cur->next = cur->next->next;
            }
        }
        return dummy->next;
    }
};