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
        void appendNode(int val);
        void insert(int val);
        node* find(int val);
        void removeNode(int val);
        void printList();
};
