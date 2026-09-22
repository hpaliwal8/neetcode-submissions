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
    int maxDepth = 0;
    public int maxDepth(TreeNode root) {
        helper(root, 1);
        return maxDepth;
    }

    public void helper(TreeNode root, int depth) {
        if(root == null) return;
        maxDepth = Math.max(maxDepth, depth);

        helper(root.left, 1 + depth);
        helper(root.right, 1 + depth);
        return;
    }
}
