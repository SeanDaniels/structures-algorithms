---
title: "Linked Lists"
permalink: /topics/linked-lists/
layout: single
toc: true
---
# Where are linked lists used?

In computer science, linked lists are used as a fundamental concept for implementing other data structures, such as stacks and queues. 

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

The ll class contains functions which act of the list structure. 
