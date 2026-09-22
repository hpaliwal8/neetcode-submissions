# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        temp_list = []
        def dfs(root):
            nonlocal temp_list
            if not root:
                return

            dfs(root.left)
            temp_list.append(root.val)
            dfs(root.right)
        dfs(root)
        return temp_list[k-1]