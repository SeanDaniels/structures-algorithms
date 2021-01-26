![Binary Search Tree](/binary-search-tree/img/bst.jpg)
# Binary Search Tree
A binary search tree (BST) is a data structure consisting of a single 'root' node and any number of internal nodes. Each node contains a pointer to a left subtree and a pointer to right subtree. A BST follows the property that the key value of each node of the left subtree is less than the key value of the root node, and the key value of each node of the right subtree is greater than the key value of the root node. Because of this property, each comparison allows approximately half of the remaining tree to be skipped when searching for a key value.

A BST allows binary search for looking up, adding, and removing items

# Time Complexity in Big O Notation
| Algorithm | Average  | Worst Case |
|:----------|:---------|:-----------|
| Space     | O(n)     | O(n)       |
| Search    | O(log n) | O(n)       |
| Insert    | O(log n) | O(n)       |
| Delete    | O(log n) | O(n)       |


# What is a 'node'
At the most basic level, a node is structure that contains a key value and a pointer to it's own left subtree and a pointer to it's own right subtree

# Searching
A BST can be searched iteratively or recursively

# Deleting
