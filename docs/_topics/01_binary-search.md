---
layout: single
title: "Binary Search"
permalink: /topics/binary-search/
---
When searching for an element within a data structure, the most basic form of searching consists of iterating through each element of the data structure and comparing it with a key value. This is known as a linear search, and as the size of the data structure increases, so does the overhead associated with checking each element. 

A binary search, which can only be applied to a sorted data structure, includes an additionaly conditional to a search miss. Where a linear search says 'this is not the element, check next position', a binary search evaluates the element at the position located some interval away. Each time the binary search misses, the interval distance is halved. 

Imagine a scenario where you are guessing a value within a given range. After each guess, you are told that the value is either greater than or less than what you guessed. If the game is scored on the number attempts needed to guess the correct value, a smart player would use range constraints to their advantage. If the range is between 0 and 100, what would your guess be? 

If you were guessing in accordance with a binary search algorithm, your first guess would be 50. If the actual value was less than that, your next guess would 25. If the actual value was greater, your next guess would be 75. This pattern continues until the actual value guessed. The beauty of this method is that half of remaining potential values are ruled out with each guess. 

Here is a c++ snippet for a binary search:
```c++
// Arguments: Array to be searched, number of elements in the array, value being searched for
int binarySearch(int searchArray[], int numberOfElements, int keyValue){
   int midPoint, startIndex = 0, endIndex = numberOfElements; 
   while(startIndex <= endIndex){
        midPoint = (startIndex + endIndex)/2;
        if(searchArray[midPoint]==keyValue){
            return midPoint;
        }
        if(searchArray[midPoint]>keyValue){
            endIndex = midPoint - 1;
        }
        else{
            startIndex = midPoint + 1;
        }
   }
   return -1;
}
```
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

The pseudo code for searching a BST is as follows:

``` c++
// point to root of bst
Node* nodePtr = root;
// while nodeptr isn't null
while(nodePtr){
    // key found, return node ptr
    if(key==nodePtr->key)return nodePtr;
    // key greater, search right
    if(key>nodePtr->key)nodePtr=nodePtr->right;
    // key less, search left
    else nodePtr=nodePtr->left;
}
return nodePtr;
```

# Inserting
Inserting a new node into a BST is accomplished with the following routined:
- Create a new node
- Locate appropriate position for new node
- Point parent node to new node

The pseudo code for inserting a new node is as follows:
``` c++
// point to root of bst
Node* nodePtr = new Node(keyValue);
if(root==nullptr)root = nodePtr;
else{
    Node* tmp = root;
    while(tmp){
    if(tmp->key > keyValue){
        // if left node is available, place new node here
        // if not, search left
    }
    else 
    // if right node is available, place node here
    // if not, search right
    
    }
}
```
# Deleting
In order to successfully remove a node from the BST, the node must be deleted and any pointers referencing the node must be updated. 

While removing a node from a BST, the underlying structure of the BST must be retained. This may require updating the removed node's parents and children. This is summarized in the following 3 cases:
- The removed node has no children
- The removed node has either a left child or a right child (1 child)
- The removed node has both a left child and a right child (2 children)
