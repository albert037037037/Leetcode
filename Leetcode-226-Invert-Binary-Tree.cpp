/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/invert-binary-tree/
 * runtime: 0ms
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};