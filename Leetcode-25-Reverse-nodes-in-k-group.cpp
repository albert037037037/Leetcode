/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
 * runtime: 8ms
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 1) return head;
        // make a dummy head for the first reverse
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur, *before, *nbrl = dummyHead;
        before = head;
        cur = head->next;
        while(cur != nullptr) {
            int cnt = 0;
            while(cur != nullptr && cnt < k-1) {
                cnt += 1;
                before->next = cur->next;
                cur->next = nbrl->next;
                nbrl->next = cur;
                cur = before->next;
            }
            // means there are left-out nodes
            if(cnt < k-1) {
                // cnt means we've done cnt times of reverse to left-out nodes
                // so we so cnt times again to return to the original order
                before = nbrl->next;
                cur = before->next;
                while(cnt--) {
                    before->next = cur->next;
                    cur->next = nbrl->next;
                    nbrl->next = cur;
                    cur = before->next;
                }
            } else { // set pointer for next loop
                nbrl = before;
                before = cur;
                if(before != nullptr) cur = before->next;
            }
        }
        return dummyHead->next;
    }
};