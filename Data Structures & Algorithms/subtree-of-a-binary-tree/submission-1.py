# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        def isSame(tree1, tree2):

            if not tree1 and not tree2:
                return True

            if not tree1 or not tree2:
                return False

            if tree1.val != tree2.val:
                return False

            left = isSame(tree1.left, tree2.left)
            right = isSame(tree1.right, tree2.right)

            return left and right

        if not root:
            return False

        if isSame(root, subRoot):
            return True

        left_search = self.isSubtree(root.left, subRoot)
        right_search = self.isSubtree(root.right, subRoot)

        return left_search or right_search
        