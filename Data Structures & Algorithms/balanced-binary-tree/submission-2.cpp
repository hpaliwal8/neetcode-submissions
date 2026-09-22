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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    
};
