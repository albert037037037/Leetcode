/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/koko-eating-bananas/submissions/
 * runtime: 56ms
 */


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        vector<int>::iterator biggest = max_element(piles.begin(), piles.end());
        int left = 1, mid, ans;
        int right = *biggest;
        int cost;
        while(left <= right){
            mid = (left + right) / 2;
            cost = 0;
            for(int i=0; i<piles.size(); i++){
                if(piles[i]%mid) cost += (piles[i]/mid + 1);
                else cost += piles[i]/mid;
            }
            if(cost <= h){
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};