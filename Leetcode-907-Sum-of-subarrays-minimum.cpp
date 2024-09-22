/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/sum-of-subarray-minimums/
 * runtime: 52ms
 */

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        std::stack<std::pair<int, int>> stk; // <num, weight>
        long long sum = 0, ans = 0;          // sum is those num * weight that will still contribute 
                                             // after adding a new num
        for(int i=0; i<arr.size(); i++) {
            int weight = 1;
            while(!stk.empty() && arr[i] < stk.top().first) {
                weight += stk.top().second;
                sum -= stk.top().first * stk.top().second;
                stk.pop();
            }
            stk.push(make_pair(arr[i], weight));
            sum += arr[i] * weight;
            ans = (ans + sum) % int(1e9+7);
        }
        return ans;
    }
};