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
    public int res = 0;
    public int goodNodes(TreeNode root) {
        if(root == null) {
            return 0;
        }

        helper(root, Integer.MIN_VALUE);

        return res;
    }

    public void helper(TreeNode root, int maxTillNow) {
        if(root == null) {
            return;
        }

        if(root.val >= maxTillNow) res++;
        maxTillNow = Math.max(maxTillNow, root.val);

        helper(root.left, maxTillNow);
        helper(root.right, maxTillNow);
    }
}
