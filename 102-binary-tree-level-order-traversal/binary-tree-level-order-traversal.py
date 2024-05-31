# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if root is None:
            return ans
        temp = []
        temp.append(root)
        while temp:
            level = []
            for _ in range(len(temp)):
                node = temp.pop(0)
                level.append(node.val)
                if node.left: 
                    temp.append(node.left)
                if node.right: 
                    temp.append(node.right)
            ans.append(level)
        return ans