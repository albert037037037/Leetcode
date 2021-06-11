/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/diameter-of-binary-tree/
 * runtime: 8ms
 */

class Solution {
private:
    pair<int, int> traverse(TreeNode* root){
        if(root == NULL) return {0, 0};
        pair<int, int> left, right;
        left = traverse(root->left);
        right = traverse(root->right);
        
        int height = max(left.first, right.first) + 1;
        int diameter = max(left.first + right.first, max(left.second, right.second));
        return {height, diameter};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        pair<int, int> ans = traverse(root);
        return ans.second;
    }
};