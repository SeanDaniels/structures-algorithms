---
title: "Linked Lists"
permalink: /topics/linked-lists/
layout: single
toc: true
---
# Where are linked lists used?

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

## Appedning a node

Appending a node is adding a node to the end of the list. Here is the implementation:

```c++
appendNode(int val){
    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    if(this->head == nullptr){
        this->head = newNode;
        return;
    }

    node* listIterator = this->head;

    while(listIterator->next){
        listIterator = listIterator->next;
    }

    listIterator->next = newNode;
    return;
}
```

## Inserting a node

For this list, the values are ordered from low to high. Insertion differs from appending in that the position of the new node within the list depends on the values of the other nodes. Here is the implementation of inserting a node into the list:

```c++
insert(int val){
    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    node* curr = this->head;
    node* prev = curr;
    // no head
    if(curr == nullptr){
        this->head = newNode;
        return;
    }
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

Here is the code for removing a node (if it exists) from the list

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

The above implementation creates a simple linked list. This type is linear. There is a definite beginning and end. 

A circular list is a cycle of nodes. The beginning and end of the list can be reached from any point in the list. Any node can be reached from any start point in the list.

Circular linked lists are used in implementing some queues, and are also useful for accessing elements continuously in an in order fashion. For example, if a scheduler that is running different processes at given intervals could use a linked list to continuously iterate through the different processes. 

# Circular linked list implementation
