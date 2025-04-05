/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/diameter-of-binary-tree/
 * runtime: 8ms
 */

class Solution {
public:
    int ans = INT_MIN;
    int solve(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        ans = max(ans, left+right);
        if(left >= right) return left+1;
        else return right+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int rl = solve(root->left);
        int rr = solve(root->right);
        ans = max(ans, rl+rr);
        return ans;
    }
};