/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/jump-game/description/
 * runtime: 0ms
 */

class Solution1 { // DP
public:
    bool canJump(vector<int>& nums) {
        vector<bool> canVisit(nums.size(), false);
        canVisit[0] = true;
        for(int i=0; i<nums.size(); i++) {
            if(canVisit[i]) {
                for(int j=i; j<nums.size() && j<=i+nums[i]; j++) {
                    canVisit[j] = true;
                }
            }
        }
        return canVisit[nums.size()-1];
    }
};
    

class Solution2 { // Greedy
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        for(int i=nums.size()-2; i>=0; i--) {
            if(i+nums[i] >= goal) goal = i;
        }
        return (goal == 0);
    }
};