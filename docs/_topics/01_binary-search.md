---
layout: single
title: "Binary Search"
permalink: /topics/binary-search/
---
When searching for an element within a data structure, the most basic form of searching consists of iterating through each element of the data structure and comparing it with a key value. This is known as a linear search, and as the size of the data structure increases, so does the overhead associated with checking each element. 

In contrast, a binary search applies a additionaly conditional to a search miss. Where a linear search says 'this is not the element, check next position', a binary search evaluates the element at the position located some interval away. Each time the binary search misses, the interval distance is halved. 

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
