/*
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/split-array-largest-sum/
 * runtime: 0ms
 */

class Solution {
public:
    bool checkValid(vector<int> arr, int k, int val) {
        int partialSum = 0;
        for(int i=0; i<arr.size(); i++) {
            partialSum += arr[i];
            if(partialSum > val) {
                k -= 1;
                partialSum = arr[i];
            }
            if(k < 0) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left <= right) {
            int mid  = left + (right - left) / 2;
            if(checkValid(nums, k-1, mid)) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return right+1;
    }
};