/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/combination-sum/description/
 * runtime: 0ms
 */

class Solution {
public:

    void makeCombination(vector<vector<int>> &res, vector<int> &comb, vector<int>& candidates, int target, int idx) {
        if(target == 0) {
            res.push_back(comb);
            return ;
        }
        else if(target < 0 || idx >= candidates.size()) {
            return ;
        } 

        comb.push_back(candidates[idx]);
        makeCombination(res, comb, candidates, target-candidates[idx], idx);
        comb.pop_back();
        makeCombination(res, comb, candidates, target, idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        makeCombination(result, comb, candidates, target, 0);
        return result;
    }
};