/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/merge-k-sorted-lists/description/
 * runtime: 3ms
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* left, const ListNode* right) {return left->val > right->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for(int i=0; i<lists.size(); i++) {
            if(lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            cur->next = smallest;
            cur = cur->next;
            minHeap.pop();

            smallest = smallest->next;
            if(smallest != nullptr) {
                minHeap.push(smallest);
            }
        }

        return dummy->next;
    }
};