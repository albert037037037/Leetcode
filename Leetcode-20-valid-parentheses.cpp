/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/valid-parentheses/
 * runtime: 0ms
 */

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if(stk.empty()) 
                    return false;
                else {
                    if(s[i] == ')' && stk.top() == '(')
                        stk.pop();
                    else if(s[i] == '}' && stk.top() == '{')
                        stk.pop();
                    else if(s[i] == ']' && stk.top() == '[')
                        stk.pop();
                    else 
                        return false;
                }
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};