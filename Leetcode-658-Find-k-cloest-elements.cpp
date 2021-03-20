/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/find-k-closest-elements/
 * runtime: 68ms
 */

#include <math.h>

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> ans;
        vector<int> re_ans;
        for(int i=0; i<arr.size(); i++){
            if(ans.size() < k)
                ans.push({abs(arr[i]-x), arr[i]});
            else{
                if(abs(arr[i]-x) < ans.top().first){
                    ans.pop();
                    ans.push({abs(arr[i]-x), arr[i]});
                }
            }
        }
        while(ans.size()){
            re_ans.push_back(ans.top().second);
            ans.pop();
        }
        sort(re_ans.begin(), re_ans.end());
        return re_ans;
    }
};