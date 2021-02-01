#include "bst.h"
// function for inserting new key into BST
void BST::insert(int key){
    Node *newNode = new Node(key);
    // BST does not have root, create root
    if(root==nullptr){
        root = newNode;
    }
    // find appropriate location for new node
    else{
        Node *tmp = root;
        // find an empty node pointer
        while(tmp!=nullptr){
            // if key of visited node is greater than new key, search left
            if(tmp->key > key){
                // if visited node's left pointer is free, set it to point to new node
                if(tmp->left==nullptr){
                    tmp->left = newNode;
                    return;
                }
                // otherwise, visit left node
                else{
                    tmp = tmp->left;
                }
            }
            // search right
            else{
                // visited node's right pointer is free
                if(tmp->right==nullptr){
                    tmp->right = newNode;
                    return;
                }
                // visit right node
                else{
                    tmp = tmp->right;
                }

            }
        }
    }
}

// functon for searching BST for a given key
bool BST::search(int key){
    if(root==nullptr)return false;
    Node *tmp = root;
    while(tmp!=nullptr){
        // key found
        if(tmp->key==key)return true;
        // search right
        else if(tmp->key<key)tmp = tmp->right;
        // search left
        else tmp = tmp->left;
    }
    // key not found
    return false;
}

// function for removing a given key
bool BST::noChildren(Node *node, Node *parent) {
  if (node->left == nullptr && node->right == nullptr) {
    // node being removed is the root of the BST
    if (parent == nullptr) {
      root = nullptr;
    }
    // node being removed is a left child
    if (parent->left == node) {
      parent->left = nullptr;
    }
    // node being removed is a right child
    else
      parent->right = nullptr;
    return true;
  }
  // node has atleast one child
  return false;
}

bool BST::oneChild(Node *node, Node *parent){
    // node being removed has right child
    if (node->right!=nullptr && node->left==nullptr) {
        // node being removed is root
        if(parent==nullptr){
            root=node->right;
        }
        // node being removed is parent right child
        else if(parent->right==node){
            parent->right = node->right;
        }
        // node being removed is parents left child
        else
            parent->left=node->right;
        return true;
            }
    // node being removed has left child
    else if (node->right==nullptr && node->left!=nullptr){
        // node being removed is root
        if(parent==nullptr)root=node->left;
        // node being removed is parents right child
        else if(parent->right==node)parent->right=node->left;
        // node being removed is parents left child
        else parent->left=node->left;
        return true;
    }

    return false;
}

void BST::twoChildren(Node *node, Node *parent){
    Node* successor = node->right;
    Node* prev = node;
    // find the smallest key in this nodes left subtree
    while(successor->left!=nullptr){
        prev = successor;
        successor = successor->left;
    }
    // check if lowest key node has no children or one child
    if(!noChildren(successor, prev)){
        oneChild(successor, prev);
    }
    successor->left = node->left;
    successor->right = node->right;

    if(parent==nullptr)root=successor;
    else if(parent->right==node)parent->right = successor;
    else parent->left = successor;
    return;
};

void BST::remove(int key) {
  Node *tmp = root;
  Node *parent = nullptr;
  while (tmp != nullptr) {
      // key found
      if (key == tmp->key){
          // check no child
          if(!noChildren(tmp, parent)){
              // check two child
              if(!oneChild(tmp, parent)){
                  noChildren(tmp, parent);
              }
          }
          delete tmp;
          break;
      }
      return;
    if (key > tmp->key) tmp = tmp->right;
    else tmp = tmp->left;
  }
}
