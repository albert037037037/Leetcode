/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/coin-change/description/
 * runtime: 20ms
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1, amount+1);
        dp[0] = 0;

        for(int i=0; i<coins.size(); i++) {
            if(coins[i] > amount) break;
            dp[coins[i]] = 1;
        }
        
        for(int i=1; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                if(i-coins[j] >= 0 && dp[i] > 1+dp[i-coins[j]]) {
                    dp[i] = 1+dp[i-coins[j]];
                }
            }
        }

        if(dp[amount] == amount+1) return -1;
        else return dp[amount];
    }
};