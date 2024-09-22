/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * runtime: 108ms
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> stk;
        int maxSize = -1, size;
        for(int i=0; i<heights.size(); i++) {
            int numberLowerBefore = 1;
            while(!stk.empty() && heights[i] < heights[stk.top().first]) {
                size = heights[stk.top().first] * (i - stk.top().first + stk.top().second - 1);
                numberLowerBefore += stk.top().second;
                if(size > maxSize)
                    maxSize = size;
                stk.pop();
            }
            stk.push(make_pair(i, numberLowerBefore));
        }
        while(!stk.empty()) {
            size = heights[stk.top().first] * (stk.top().second + heights.size()- stk.top().first - 1);
            if(size > maxSize)
                maxSize = size;
            stk.pop();
        } 
        return maxSize;
    }
};