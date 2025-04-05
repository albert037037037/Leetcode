/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/word-break/description/
 * runtime: 0ms
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for(int i=1; i<=s.length(); i++) {
            for(auto word : wordDict) {
                int cmpPoint = i - word.length();
                if(cmpPoint >= 0 && s.substr(cmpPoint, word.length()) == word) {
                    dp[i] = dp[cmpPoint];
                }
                if(dp[i] == true) break;
            }
        }
        return dp[s.length()];
    }
};