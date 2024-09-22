/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/
 * runtime: 35ms
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode *tmpA = headA, *tmpB = headB;
        while(tmpA != tmpB) {
            tmpA = (tmpA != nullptr) ? tmpA->next : headB;
            tmpB = (tmpB != nullptr) ? tmpB->next : headA;
        }
        if(tmpA != nullptr) return tmpA;
        return nullptr;
    }
};