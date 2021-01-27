# Binary Search Tree
![Binary Search Tree](/binary-search-tree/img/bst.jpg)


A binary search tree (BST) is a data structure consisting of a single 'root' node and any number of internal nodes. Each node contains a pointer to a left subtree and a pointer to right subtree. A BST follows the property that the key value of each node of the left subtree is less than the key value of the root node, and the key value of each node of the right subtree is greater than the key value of the root node. Because of this property, each comparison allows approximately half of the remaining tree to be skipped when searching for a key value.

A BST allows binary search for looking up, adding, and removing items

# Time Complexity in Big O Notation
| Algorithm | Average  | Worst Case |
|:----------|:---------|:-----------|
| Space     | O(n)     | O(n)       |
| Search    | O(log n) | O(n)       |
| Insert    | O(log n) | O(n)       |
| Delete    | O(log n) | O(n)       |


# Nodes
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


In order to remove a node from a BST
Removing a node from a BST 
