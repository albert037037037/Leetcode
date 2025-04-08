/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/copy-list-with-random-pointer/description/
 * runtime: 0ms
 */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        unordered_map<Node*, int> umap;
        Node* cur = head;
        vector<Node*> vec;
        int idx = 0;

        while(cur != nullptr) {
            // mapping
            umap[cur] = idx;
            
            // create vector of ListNode
            vec.push_back(new Node(cur->val));
            idx += 1;
            cur = cur->next;
        }

        
        cur = head; idx = 0;
        while(cur->next != nullptr) {
            vec[idx]->next = vec[idx+1];
            if(cur->random != nullptr) vec[idx]->random = vec[umap[cur->random]];
            idx+=1;
            cur = cur->next;
        }
        vec[idx]->next = nullptr;
        if(cur->random != nullptr) vec[idx]->random = vec[umap[cur->random]];
        return vec[0];
    }
};