/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/next-greater-element-i/
 * runtime: 3ms
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp(1e4+1, -1);
        vector<int> ans;
        std::stack<int> stk;
        for(int i=nums2.size()-1; i>=0; i--) {
            while(!stk.empty() && nums2[i] >= stk.top())
                stk.pop();
            if(!stk.empty()) 
                mp[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};