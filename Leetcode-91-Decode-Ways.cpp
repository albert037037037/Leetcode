/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/decode-ways/description/
 * runtime: 0ms
 */

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp (s.length()+1, 1);
        for(int i=2; i<=s.length(); i++) {
            char cur = s[i-1];
            char before = s[i-2];
            if(cur == '0') {
                if(before == '1' || before == '2') {
                    dp[i] = dp[i-2];
                }
                else {
                    return 0;
                }
            } else if(before == '1') {
                dp[i] = dp[i-1] + dp[i-2];
            } else if(before == '2' && cur <= '6') {
                dp[i] = dp[i-1] + dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[s.length()];
    }
};