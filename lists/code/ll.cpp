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

void ll::appendCircle(int val){
    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    if(this->head == nullptr){
        this->head = newNode;
        newNode->next = newNode;
        return;
    }

    node* listIterator = this->head;

    while(listIterator->next != this->head){
        listIterator = listIterator->next;
    }

    listIterator->next = newNode;
    newNode->next = this->head;
    return;
}

void ll::insertCircle(int val){
    node* curr = this->head;
    node* prev = curr;
    node* newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;
    // list is empty
    if(curr == nullptr){
        this->head = newNode;
        newNode->next = this->head;
        return;
    }
    // list is not empty
    // single entry in list
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

    // check tail
    if(curr->data > val){
        prev->next = newNode;
        newNode->next = curr;
        return;
    }

    curr->next = newNode;
    newNode->next = this->head;
    //


}

void ll::printCircle(){
    node* listIterator = this->head;
    if(!listIterator) return;
    cout << "*head* -> ";
    while (listIterator->next != head) {
        cout << listIterator->data << " -> ";
        listIterator = listIterator->next;
    }
    cout << listIterator->data;
    cout << " -> *head*\n";


}

void doInsertions(ll &thisList){
    vector<int> insertions = {3, 1, 2, 2, 4, 4};
    for(auto x : insertions){
        thisList.insert(x);
    }
    cout << "List after insertions:\n";
    thisList.printList();
}

void doDeletions(ll &thisList){
    vector<int> removals = {4, 4, 1};
    for(auto x : removals){
        thisList.removeNode(x);
    }
    cout << "List after removals:\n";
    thisList.printList();
}

void doSearch(ll &thisList){
    int searchValue = 6;
    node* location = thisList.find(searchValue);
    if(!location){
        cout << searchValue << " not found in list" << endl;
    }
}

int main(){
    ll linearList;
    ll circularList;
    circularList.insertCircle(3);
    circularList.insertCircle(1);
    circularList.insertCircle(2);
    circularList.printCircle();
    // doInsertions(linearList);
    // doSearch(linearList);
    // doDeletions(linearList);
    return 0;
}
