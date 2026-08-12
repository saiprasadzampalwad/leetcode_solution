# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
             def findPair(root: Optional[TreeNode], k: int, seen: Set[int]) -> bool:
                 if not root: 
                    return False 
                 if k - root.val in seen:
                     return True
                 seen.add(root.val)
                 return findPair(root.left, k, seen) or findPair(root.right, k, seen)
             return findPair(root, k, set())