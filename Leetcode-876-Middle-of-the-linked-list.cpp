/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/middle-of-the-linked-list/submissions/
 * runtime: 0ms
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast->next!=NULL && fast->next->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next == NULL) return slow;
        else if(fast->next->next==NULL) return (slow->next);
        return NULL;
    }
};