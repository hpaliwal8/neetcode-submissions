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
    public int goodNodes(TreeNode root) {
        if(root == null) {
            return 0;
        }

        int[] res = new int[1];
        helper(root, Integer.MIN_VALUE, res);
        return res[0];
    }

    public void helper(TreeNode root, int maxTillNow, int[] res) {
        if(root == null) {
            return;
        }

        if(root.val >= maxTillNow) res[0]++;
        maxTillNow = Math.max(maxTillNow, root.val);

        helper(root.left, maxTillNow, res);
        helper(root.right, maxTillNow, res);
    }
}
