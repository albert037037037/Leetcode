/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 * runtime: 0ms
 */

class Solution {
public:
    TreeNode* prev = nullptr;
    int minAbs = INT_MAX;
    void solve(TreeNode* root) {
        if(root->left != nullptr) {
            solve(root->left);
        }
        if(prev != nullptr) minAbs = min(minAbs, abs(root->val - prev->val));
        prev = root;
        if(root->right != nullptr) {
            solve(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return minAbs;
    }
};