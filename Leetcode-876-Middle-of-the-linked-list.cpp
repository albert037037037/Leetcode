/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/middle-of-the-linked-list/submissions/
 * runtime: 0ms
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next == nullptr) return slow;
        else return slow->next;
        return nullptr;
    }
};