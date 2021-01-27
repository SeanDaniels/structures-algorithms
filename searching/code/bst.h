#ifndef __BST_H_
#define __BST_H_
using namespace std;
// Binary search tree class definition
class BST{
    public:
    // BSTs consist of a central root node and internal nodes
    // Node class definition
    class Node{
        public:
        int key;
        Node *right;
        Node *left;

        // Constructor for node
        Node(int k, Node *l = nullptr, Node *r = nullptr){
            key = k;
            right = r;
            left = l;
        }
    };

    // BST root data member
    Node *root;

    // constructor for BST
    BST(){ root = nullptr;}

    // destructor
    ~BST(){
        /* while(root) */
        /*     remove(root->key); */
    }

    // function for inserting a key into the BST
    void insert(int key);

    // function for searching tree for key
    bool search(int key);

    // function for removing key from tree
    void remove(int key);

    // function for removing a node with no children
    bool noChildren(Node* node, Node* parent);

    // function for removing a node with one child
    bool oneChild(Node* node, Node* parent);

    // function for removing a node with two children
    void twoChildren(Node* node, Node* parent);


};

#endif // __BST_H_
