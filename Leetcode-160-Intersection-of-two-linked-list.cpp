/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/
 * runtime: 40ms
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* runA = headA, *runB = headB, *intersect = NULL;
        int cntA = 0, cntB = 0;
        while(runA != NULL){
            cntA++;
            runA = runA->next;
        }
        while(runB != NULL){
            cntB++;
            runB = runB->next;
        }
        if(cntA > cntB){
            for(int i=0; i<cntA-cntB; i++) headA = headA->next;
        }
        else {
            for(int i=0; i<cntB-cntA; i++) headB = headB->next;
        }
        while(headA != NULL && headB != NULL){
            if(headA == headB){
                intersect = headA;
                break;
            }
            headA = headA->next;
            headB = headB->next;
        } 
        return intersect;
    }
};