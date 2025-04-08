/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/reorder-list/description/
 * runtime: 0ms
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = nullptr, *cur = slow->next;
        slow->next = nullptr;
        while(cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        ListNode *revCur = prev;
        cur = head;
        while(cur != nullptr && revCur != nullptr) {
            ListNode* tmp = revCur->next;
            revCur->next = cur->next;
            cur->next = revCur;
            cur = revCur->next;
            revCur = tmp;
        }
    }
};