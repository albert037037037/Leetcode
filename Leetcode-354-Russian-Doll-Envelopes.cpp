/*
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/russian-doll-envelopes/
 * runtime: 200ms
 */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> ans;
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> a, const vector<int> b) {
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        for(auto envelope : envelopes) {
            if(!ans.empty()) {
                auto lb = lower_bound(ans.begin(), ans.end(), envelope[1]);
                if(lb == ans.end()) {
                    ans.push_back(envelope[1]);
                } else {
                    *lb = envelope[1];
                }
            } else {
                ans.push_back(envelope[1]);
            }
        }
        return ans.size();
    }
};