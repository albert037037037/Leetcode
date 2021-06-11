/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/invert-binary-tree/
 * runtime: 0ms
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* tmp = invertTree(root->right);
        tmp = invertTree(root->left);
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};