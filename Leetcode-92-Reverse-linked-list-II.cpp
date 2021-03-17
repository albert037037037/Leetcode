/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/reverse-linked-list-ii/
 * runtime: 4ms
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL, *cur = head, *cur_next = NULL, *tmp = NULL, *record_first = NULL;
        for(int i=1; i<left; i++){
            prev = cur;
            cur = cur->next;
        }
        cur_next = cur->next;
        record_first = cur;
        for(int i=left; i<right; i++){
            tmp = cur_next->next;
            cur_next->next = cur;
            cur = cur_next;
            cur_next = tmp;
        }
        if(prev != NULL){
            prev->next = cur;
            record_first->next = cur_next;
        }
        else{
            record_first->next = cur_next;
            head = cur;
        }
        return head;
    }
};