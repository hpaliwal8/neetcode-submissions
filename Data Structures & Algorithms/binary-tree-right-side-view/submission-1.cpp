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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size-1;i++) {
                TreeNode* element = q.front();
                q.pop();
                if(element -> left) q.push(element->left);
                if(element -> right) q.push(element->right);
            }
            TreeNode* element = q.front();
            q.pop();
            if(element -> left) q.push(element->left);
            if(element -> right) q.push(element->right);
            res.push_back(element->val);
        }

        return res;
    }
};
