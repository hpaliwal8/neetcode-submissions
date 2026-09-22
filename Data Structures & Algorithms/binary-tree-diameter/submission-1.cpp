/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int res = 0;
        helper(root, res);
        return res;
    }


    void helper(TreeNode* root, int& res) {
        if(!root) return;

        res = max(res, maxDepth(root->left) + maxDepth(root->right));
        helper(root->left, res);
        helper(root->right, res);
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
