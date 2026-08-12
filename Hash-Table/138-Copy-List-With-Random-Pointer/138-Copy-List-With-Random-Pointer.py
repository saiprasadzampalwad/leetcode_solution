"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
# Definition for a Node.
class Node:
    def __init__(self, val=0, next=None, random=None):
        self.val = val
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None

        # Step 1: Create new nodes and interweave them with the original nodes
        curr = head
        while curr:
            new_node = Node(curr.val)
            new_node.next = curr.next
            curr.next = new_node
            curr = new_node.next

        # Step 2: Set the random pointers of the new nodes
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next

        # Step 3: Separate the new nodes from the original nodes to form the deep copy
        curr = head
        copy_head = head.next
        while curr:
            new_node = curr.next
            curr.next = new_node.next
            if new_node.next:
                new_node.next = new_node.next.next
            curr = curr.next

        return copy_head
