/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * runtime: 108ms
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int LtoR[100000]; // to find the next smaller number from right to left
        vector<int> stk;
        int max = 0;
        for(int i=0; i<heights.size(); i++){
            while(stk.size() && heights[i] < heights[stk.back()]){
                LtoR[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i); // push index
        }
        while(stk.size()){ // If left in stack, means it can make a rectangle from itself to rightmost
            LtoR[stk.back()] = heights.size();
            stk.pop_back();
        }

        for(int i=heights.size()-1; i>=0; i--){
            while(stk.size() && heights[i] < heights[stk.back()]){
                // after finding the smaller number from right to left, we can calculate the largest rectangle this heights contributes
                if(heights[stk.back()] * (LtoR[stk.back()] - i -1) > max) {
                    max = heights[stk.back()] * (LtoR[stk.back()] - i -1);
                }
                stk.pop_back();
            }
            stk.push_back(i);  // push index
        }
        while(stk.size()){ // If left in stack, means it can make a rectangle from itself to leftmost
            if(heights[stk.back()] * LtoR[stk.back()] > max) {
                max = heights[stk.back()] * LtoR[stk.back()];
            }
            stk.pop_back();
        }
        return max;
    }
};