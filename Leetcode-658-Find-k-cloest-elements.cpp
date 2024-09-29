/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/find-k-closest-elements/
 * runtime: 20ms
 */

#include <cmath>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto pos = std::lower_bound(arr.begin(), arr.end(), x);
        int right = std::distance(arr.begin(), pos);
        int left = right - 1;
        std::vector<int> ans;
        while(k > 0 && left >= 0 && right < arr.size()) {
            if(abs(arr[left] - x) <= abs(arr[right] - x)) {
                ans.push_back(arr[left]);
                left -= 1;
            } else {
                ans.push_back(arr[right]);
                right += 1;
            }
            k -= 1;
        }
        
        if(k != 0) {
            while(left >= 0 && k > 0) {
                ans.push_back(arr[left]);
                left -= 1;
                k -= 1;
            }
            while(right < arr.size() && k > 0) {
                ans.push_back(arr[right]);
                right += 1;
                k -= 1;
            }
        }
        std::sort(ans.begin(), ans.end());
        
        return ans;
    }
};