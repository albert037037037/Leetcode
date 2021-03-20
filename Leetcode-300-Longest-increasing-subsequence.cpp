/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/longest-increasing-subsequence/
 * runtime: 8ms
 */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> binary;
        int left, right, mid;
        binary.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < binary.front()) binary.front() = nums[i];
            else if(nums[i] > binary.back()) binary.push_back(nums[i]);
            else{
                left = 0; right = binary.size()-1;
                while(left <= right){
                    mid = (left + right) / 2;
                    if(nums[i] < binary[mid]){
                        right = mid-1;
                    }
                    else if(nums[i] > binary[mid]){
                        left = mid+1;
                    }
                    else{
                        left = mid;
                        break;
                    }
                }
                binary[left] = nums[i];
            }
        }
        
        return binary.size();
    }
};