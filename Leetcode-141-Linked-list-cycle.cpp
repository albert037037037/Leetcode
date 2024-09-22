/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/linked-list-cycle/
 * runtime: 8ms
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            if(fast->next == slow) return true; 
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};