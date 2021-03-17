/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/valid-parentheses/
 * runtime: 0ms
 */

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> mystack;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                mystack.push(s[i]);
            }
            else{
                if(mystack.size() == 0) {
                        return false;
                }
                else if(s[i] == ')'){
                    if(mystack.top() == '(') mystack.pop();
                    else {
                        return false;
                    }
                }
                else if(s[i] == ']'){
                    if(mystack.top() == '[') mystack.pop();
                    else {
                        return false;
                    }
                }
                else if(s[i] == '}'){
                    if(mystack.top() == '{') mystack.pop();
                    else {
                        return false;
                    }
                }
            }
        }
        if(!mystack.empty()) return false;
        return true;
    }
};