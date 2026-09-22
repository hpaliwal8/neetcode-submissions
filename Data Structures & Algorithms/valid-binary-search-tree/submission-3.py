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
        
        isLeftGood = False
        isRightGood = False
        if root.left:
            isLeftGood = isLeftGood or root.val > root.left.val
        else: 
            isLeftGood = True

        if root.right:
            isRightGood = isRightGood or root.val < root.right.val
        else: 
            isRightGood = True

        # print(root.val, isLeftGood, isRightGood)

        return isLeftGood and isRightGood and self.isValidBST(root.left) and self.isValidBST(root.right)