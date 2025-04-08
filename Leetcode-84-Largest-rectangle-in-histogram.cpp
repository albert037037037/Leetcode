/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * runtime: 108ms
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk; // pair<index, # of bar higher than me previous;
        int largest = 0;
        for(int i=0; i<heights.size(); i++) {
            int higher = 0;
            while(!stk.empty() && heights[i] < heights[stk.top().first]) { // calculate the area by previous bar
                int width = (i-stk.top().first) + stk.top().second;
                largest = max(largest, width*heights[stk.top().first]);
                higher += stk.top().second+1;
                stk.pop();
            }
            stk.push(make_pair(i, higher));
        }

        while(!stk.empty()) {
            int width = (heights.size()-stk.top().first) + stk.top().second;
            largest = max(largest, width*heights[stk.top().first]);
            stk.pop();
        }

        return largest;
    }
};