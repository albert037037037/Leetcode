/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/132-pattern/description/
 * runtime: 86ms
 */

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        std::vector<int> minValues(nums.size());
        int minV = nums[0];
        // Use O(N) to find minvalue from index 0 to index i;
        for(int i=0; i<nums.size(); i++) {
            minValues[i] = minV;
            minV = min(nums[i], minV);
        }

        std::stack<int> stk;
        for(int i=nums.size()-1; i>=0; i--) {
            while(!stk.empty() && stk.top() <= minValues[i]){ // when i becomes smaller, minValues[i] become larger
                stk.pop();                                    // so if top is smaller then minValues[i] it is not
            }                                                 // possible that stk value be the 2 of the 132 pattern
            if(!stk.empty() && stk.top() < nums[i]) {
                return true;
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
