# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = 0
        def helper(root, maxTillNow):
            nonlocal res
            if not root:
                return
            # print(maxTillNow, root.val)
            if maxTillNow <= root.val:
                res += 1

            maxTillNow = max(maxTillNow, root.val)
            helper(root.left, maxTillNow)
            helper(root.right, maxTillNow)

        helper(root, float('-inf'))
        return res
            
            