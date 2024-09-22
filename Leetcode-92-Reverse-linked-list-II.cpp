/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/reverse-linked-list-ii/
 * runtime: 0ms
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr || left == right) return head;
        // a dummy head for the situation that left = 1
        ListNode *cur, *before, *nbrl, *tmp;
        ListNode *dummyHead = new ListNode(0, head);
        nbrl = dummyHead;
        // move cur to left - 1
        int cnt = 1;
        while(cnt < left) {
            cnt += 1;
            nbrl = nbrl->next;
        }
        before = nbrl->next;
        cur = before->next;
        // keep inserting cur to next of nbrl
        cnt = right - left;
        while(cnt > 0){
            cnt -= 1;
            before->next = cur->next;
            cur->next = nbrl->next;
            nbrl->next = cur;
            cur = before->next;
        }
        if(left == 1) head = nbrl->next;
        return head;
    }
};