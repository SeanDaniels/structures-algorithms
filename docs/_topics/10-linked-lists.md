---
title: "Linked Lists"
permalink: /topics/linked-lists/
layout: single
toc: true
---
# Where are linked lists used?

![Example Circular Linked List](/structures-algorithms/assets/images/linear-ll.jpg)

Linked lists are used as a fundamental concept for implementing other data structures, such as stacks and queues. 

Linked lists are also used for specific implementations of certain varieties of other data structures, like the chaining method of handling hash table collisions.

# Value of a linked list

Linked lists allow for a collection of data to be contained in an associated structure with out declaring the number elements. 

# Implementation

A simple linked list is a collection of nodes. Each node contains some value and a pointer to the next node. The list structure can simply be a reference to the first node. Here is an example:

```c++
struct node{
    int data;
    struct node* next;
};


class ll {
    public:
        struct node* head;
        ll(){ head = nullptr;}
        void appendNode(int val);
        void insert(int val);
        node* find(int val);
        void removeNode(int val);
        void printList();
};
```

The ll class contains functions which act of the list structure. The class is instantiated with it's head pointing to nothing.
## Adding a node to the list

There are three cases for adding a node to linked list:

- The list is empty
- The list has a single node
- The list has more than one node

If the node is being appended to the list, only two of the cases need to be considered: 

- The list is empty
- The list is not empty

### Appending a node

Appending a node is adding a node to the end of the list. Here is the implementation:

```c++
appendNode(int val){
    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    // empty list, update head
    if(this->head == nullptr){
        this->head = newNode;
        return;
    }
    
    // non-empty list, find end
    node* listIterator = this->head;

    while(listIterator->next){
        listIterator = listIterator->next;
    }

    listIterator->next = newNode;
    return;
}
```

### Inserting a node

For this list, the values are ordered from low to high. Insertion differs from appending in that the position of the new node within the list depends on the values of the other nodes. Here is the implementation of inserting a node into the list:


```c++
insert(int val){
    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    node* curr = this->head;
    node* prev = curr;
    // empty list
    if(curr == nullptr){
        this->head = newNode;
        return;
    }
    // non-empty list
    while(curr){
      if (curr->data > newNode->data) {
        // new data < head data
        if (curr == prev) {
          newNode->next = curr;
          this->head = newNode;
          return;
        }
        // new data inserted between two existing nodes
        prev->next = newNode;
        newNode->next = curr;
        return;
      }
      // update previous, increment current
      prev = curr;
      curr = curr->next;
    }
    // new node is greater than tail, append it
    prev->next = newNode;
}
```

## Removing a node

Removing a node from a linked list involves locating the target node, updating the pointers that are effected by the removal of the target node, and removing the node.

Here is the code for removing a node (if it exists) from the list:

```c++
removeNode(int val){
    node* curr = this->head;
    node* prev = curr;
    if(!curr){
        return;
    }
    while(curr){
        if(curr->data == val){
            if(curr==this->head){
                this->head = curr->next;
                delete(curr);
                return;
            }
            prev->next = curr->next;
            delete(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
```

# Circular linked list

![Example Circular Linked List](/structures-algorithms/assets/images/circular-ll.jpg)

The above implementation creates a simple linked list. This type of list is linear. There is a definite beginning and end. 

A circular list is a cycle of nodes. The beginning and end of the list can be reached from any point in the list. Any node can be reached from any start point in the list.

Circular linked lists are used in implementing some queues, and are also useful for accessing elements continuously in an in order fashion. For example, if a scheduler is running different processes at given intervals could use a linked list to continuously iterate through the different processes. 

# Circular linked list implementation

The general structure of a circular linked list is mostly the same as that of a linear linked list. The only difference between the two structures is that the 'last' node in the list points to the head of the list.

When performing operations on a linear linked list, iteration through the list ends when the iterator is updated to a null pointer. In a non-empty circular linked list, there are no nodes which contain a null pointer, so iteration is controlled by storing a pointer to the head of the list, and halting iteration when the iterator's next pointer points to the head of the list. 

Also, insertion into a circular linked list needs to account for potential changes in the tail node's pointer, with respect to the head of the list.

Insertion into an circular linked list looks like this:

```c++
void insert(int val){
    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    // list is empty
    if(this->head== nullptr){
        this->head = newNode;
        // point new node to itself
        newNode->next = this->head;
        return;
    }

    if(curr->next == this->head){
        // head->value < new value
      if (curr->data < val) {
        curr->next = newNode;
        newNode->next = this->head;
        return;
      }
      // head value > new value
      this->head = newNode;
      newNode->next = curr;
      curr->next = this->head;
      return;
    }
    // more than one entry in list
    while(curr->next != this->head){
        // found a value that is greater than new value
        // new node needs to point to curr node
        if(curr->data > val){
            // if new value is less than head value
            if(prev==curr){
                // find current tail
                while(prev->next != this->head) {
                    prev = prev->next;
                }
                //set current tail to point to new node
                prev->next = newNode;
                newNode->next = curr;
                this->head = newNode;
                return;
            }
        }
        prev = curr;
        curr = curr->next;
}
}
```

Deletion:

```c++
deleteCircle(int val){
    if(this->head == nullptr){
        return;
    }
    node* curr = this->head;
    node* prev = curr;

    // single node in list contains sought data
    if(curr->next==this->head && curr->data == val){
        this->head = nullptr;
        delete(curr);
        return;
    }

    while(curr->next!=this->head){
        if(curr->data == val){
            // multiple nodes, head contains sought data
            if(prev == curr){
                while(prev->next!=this->head){
                    prev = prev->next;
                }
                this->head = curr->next;
                prev->next = this->head;
                delete(curr);
                return;
            }
            prev->next = curr->next;
            delete(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if(curr->data == val){
        prev->next = head;
        delete(curr);
        return;
    }
}
```
