/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
 * runtime: 12ms
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        int n = 0;
        ListNode* cnt = head;
        ListNode* cur = head;
        ListNode* curnext = head->next;
        ListNode* record_first = head;
        ListNode* record_last;
        ListNode* prev = NULL;
        while(cnt!=NULL){
            cnt = cnt->next;
            n++;
        }
        for(int i=0; i<n/k; i++){
            record_first = cur;
            record_last = prev;
            for(int j=0; j<k-1; j++){
                prev = cur;
                cur = curnext;
                curnext = curnext->next;
                cur->next = prev;
            }
            cout << "cur = " << cur->val << endl;
            if(record_last!=NULL)cout << "record_last = " << record_last->val << endl;
            if(i==0) head = cur;
            if(record_last!=NULL)record_last->next = cur;
            record_first->next = curnext;
            prev = record_first;
            cur = curnext;
            if(curnext !=NULL && curnext->next != NULL)curnext = curnext->next;
        }
        return head;
    }
};