/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/partition-list/
 * runtime: 0ms
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *lh = nullptr, *lt = nullptr, *bh = nullptr, *bt = nullptr;
        while(head != nullptr)
        {
            if(head->val >= x) {
                if(bh == nullptr) {
                    bh = head;
                    bt = head;
                } else {
                    bt->next = head;
                    bt = bt->next;
                }
            } else{
                if(lh == nullptr) {
                    lh = head;
                    lt = head;
                } else {
                    lt->next = head;
                    lt = lt->next;
                }
            }
            head = head->next;
        }
        if(lh != nullptr) lt->next = bh;
        else lh = bh;
        if(bt != nullptr) bt->next = nullptr;
        return lh;
    }
};