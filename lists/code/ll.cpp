#include <bits/stdc++.h>
#include "ll.h"
using namespace std;

void ll::appendNode(int val){
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

void ll::insert(int val){
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

node* ll::find(int val){
    node* listIterator = this->head;
    while(listIterator){
        if(listIterator->data == val){
            return listIterator;
        }
        listIterator = listIterator->next;
    }
    return listIterator;
}

void ll::removeNode(int val){
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

void ll::printList(){
    node* listIterator = this->head;
    while(listIterator){
      cout << listIterator->data;
      if(listIterator->next){
          cout << " -> ";
      }
      listIterator = listIterator->next;
    }
    cout << endl;
}

int main(){
    ll tempList;
    int searchValue = 6;
    vector<int> insertions = {3, 1, 2, 2, 4, 4};
    vector<int> removals = {4, 4, 1};
    for(auto x : insertions){
        tempList.insert(x);
    }
    cout << "List after insertions:\n";
    tempList.printList();
    node* location = tempList.find(searchValue);
    if(!location){
        cout << searchValue << " not found in list" << endl;
    }
    for(auto x : removals){
        tempList.removeNode(x);
    }
    cout << "List after removals:\n";
    tempList.printList();
    return 0;
}
