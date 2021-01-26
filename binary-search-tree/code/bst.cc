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
