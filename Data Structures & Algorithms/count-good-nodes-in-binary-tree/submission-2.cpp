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
    int goodNodes(TreeNode* root) {
        int res = 0;

        if(!root) return res;

        helper(root, res, INT_MIN);
        return res;
    }

    void helper(TreeNode* root, int& res, int max) {
        if(!root) return;

        if(max <= root->val){
            max = root->val;
            res += 1;
        } 

        helper(root->left, res, max);
        helper(root->right, res, max);
    }
};
