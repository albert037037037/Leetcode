/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/sum-of-subarray-minimums/
 * runtime: 80ms
 */

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>> S;
        const int modulo = 1e9+7;
        long long ans = 0;
        long long sum = 0;
        for(int i=0; i<arr.size(); i++){
            int weight = 1;
            while(!S.empty() && arr[i] < S.top().first){
                sum -= S.top().first * S.top().second;
                weight += S.top().second; // absorb the contribution
                S.pop();
            }
            S.push({arr[i], weight});
            sum += arr[i] * weight;
            ans = (ans + sum) % modulo;
        }
        return ans;
    }
};