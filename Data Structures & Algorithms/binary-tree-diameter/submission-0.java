/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    int res = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        helper(root);
        return res;
    }

    public void helper(TreeNode root) {
        if(root == null) return;

        res = Math.max(res, depth(root.left) + depth(root.right));

        helper(root.left);
        helper(root.right);
    }

    public int depth(TreeNode root) {
        if(root == null) {
            return 0;
        }

        return 1 + Math.max(depth(root.left), depth(root.right));
    }
}
