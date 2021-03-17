/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/remove-k-digits/
 * runtime: 0ms
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(int i=0; i<num.length(); i++){
            while(!ans.empty() && num[i] < ans.back() && k!=0){
                k--;
                ans.pop_back();
            }
            if(!ans.empty() || num[i] != '0') ans.push_back(num[i]);
        }
        
        while(k-- && !ans.empty()){
            ans.pop_back();
        }
        
        if(ans.size() == 0) return "0";
        else return ans;
    }
};