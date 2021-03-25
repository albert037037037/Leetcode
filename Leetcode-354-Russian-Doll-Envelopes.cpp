/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/russian-doll-envelopes/
 * runtime: 200ms
 */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), 
        [](vector<int> a, vector<int> b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        int left, right, mid;
        vector<int> ans;
        for(vector<int> envelope : envelopes){
            int num = envelope[1];
            if(!ans.size()) ans.push_back(num);
            else if(num > ans.back()) ans.push_back(num);
            else if(num < ans.front()) ans.front() = num;
            else{
                left = 0; right = ans.size()-1;
                while(left < right){
                    mid = left + (right-left)/2;
                    if(num > ans[mid]){
                        left = mid + 1;
                    }
                    else right = mid;
                }
                ans[right] = num;
            }
        }
        return ans.size();
    }
};