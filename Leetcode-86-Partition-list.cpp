/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/partition-list/
 * runtime: 8ms
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* LessHead = nullptr, *GreaterHead = nullptr;
        ListNode* lesstmp = nullptr, *greatertmp = nullptr;
        while(head!=nullptr){
            if(head->val < x){
                if(LessHead == nullptr){
                    LessHead = new ListNode(head->val);
                    lesstmp = LessHead;
                }
                else{
                    lesstmp->next = new ListNode(head->val);
                    lesstmp = lesstmp->next;
                }
            }
            else{
                if(GreaterHead == nullptr){
                    GreaterHead = new ListNode(head->val);
                    greatertmp = GreaterHead;
                }
                else{
                    greatertmp->next = new ListNode(head->val);
                    greatertmp = greatertmp->next;
                }
            }
            head = head->next;
        }
        if(LessHead == nullptr) return GreaterHead;
        else lesstmp->next = GreaterHead;
        return LessHead;
    }
};