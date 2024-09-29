/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/longest-increasing-subsequence/
 * runtime: 4ms
 */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> lis;
        for(int i=0; i<nums.size(); i++) {
            if(lis.empty() || lis.back() < nums[i]) {
                lis.push_back(nums[i]);
            } else {
                auto it = std::lower_bound(lis.begin(), lis.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return lis.size();
    }
};