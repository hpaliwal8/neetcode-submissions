# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        def helper(root, minval, maxval):
            if not root:
                return True

            return root.val > minval and root.val < maxval and helper(root.left, minval, root.val) and helper(root.right, root.val, maxval)

        return helper(root, float('-inf'), float('inf'))

