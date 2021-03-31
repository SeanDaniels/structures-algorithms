#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

class ll {
    public:
        struct node* head;
        ll(){ head = nullptr;}
        // linear linked list functions
        void appendNode(int val);
        void insert(int val);
        node* find(int val);
        void removeNode(int val);
        void printList();
        // circular linked list functions
        void appendCircle(int val);
        void printCircle();
        void insertCircle(int val);
        void deleteCircle(int val);
};
