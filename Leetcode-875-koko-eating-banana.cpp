/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/koko-eating-bananas/submissions/
 * runtime: 29ms
 */


class Solution {
public:
    bool tryK(vector<int> &piles, int k, int h) {
        for(int i=0; i<piles.size(); i++) {
            h -= piles[i] / k;
            if (piles[i] % k != 0) h -= 1;
        }
        if(h < 0) return false;
        else return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxE = *std::max_element(piles.begin(), piles.end());
        int left = 1, right = maxE;
        while(left <= right) {
            int mid = (left+right) / 2;
            if(tryK(piles, mid, h)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ceil(double((left+right))/2);
    }
};