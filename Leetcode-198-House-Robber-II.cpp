/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/house-robber-ii/description/
 * runtime: 0ms
 */

class Solution {
public:
    int robber1(vector<int> &nums, int left, int right) {
        vector<int> dp(nums.size(), 0);
        dp[left] = nums[left];
        dp[left+1] = max(nums[left], nums[left+1]);
        for(int i=left+2; i<right; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[right-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);
        int ans = 0;
        ans = robber1(nums, 0, nums.size()-1);
        ans = max(ans, robber1(nums, 1, nums.size()));
        return ans;
    }
};