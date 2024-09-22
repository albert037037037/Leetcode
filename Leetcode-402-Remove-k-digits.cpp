/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/remove-k-digits/
 * runtime: 0ms
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::string ans;
        for(int i=0; i<num.length(); i++) {
            while(!ans.empty() && k > 0 && num[i] < ans.back()) {
                ans.pop_back();
                k -= 1;
            }
            if(!ans.empty() || num[i] != '0')
                ans.push_back(num[i]);
        }

        while(k > 0 && !ans.empty()) {
            k -= 1;
            ans.pop_back();
        }

        if(!ans.empty())
            return ans;
        else 
            return "0";
    }
};