/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/linked-list-cycle/
 * runtime: 8ms
 */

bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    while(head->val!=100001 && head->next != NULL){
        head->val = 100001;
        head = head->next;
    }
    if(head->next == NULL) return false;
    else return true;
}