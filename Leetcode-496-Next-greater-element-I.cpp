/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/next-greater-element-i/
 * runtime: 4ms
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::stack<int> myStack;
        int big[10001]; 
        for(int i=0; i<10001; i++) big[i] = -1;
        
        //myStack.push(10001);
        for(int i=nums2.size()-1; i>=0; i--){
            if(myStack.empty()){
                myStack.push(nums2[i]);
            }
            else if(nums2[i] > myStack.top()){
                while(!myStack.empty() && nums2[i] > myStack.top()){
                    myStack.pop();
                }
                if(!myStack.empty()) big[nums2[i]] = myStack.top();
                myStack.push(nums2[i]);
            }
            else{
                big[nums2[i]] = myStack.top();
                myStack.push(nums2[i]);
            }
            
        }
        for(int i=0; i<nums1.size(); i++){
            nums1[i] = big[nums1[i]];
        }
        return nums1;
    }
};