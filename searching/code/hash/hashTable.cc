#include "hashTable.h"
using std::cout;
using std::endl;
//#define VERBOSE
int HashTable::hashFunc(int value){
    return value % this->tableSize;
}

bool HashTable::insert(int value){
    int key = hashFunc(value);
    #ifdef VERBOSE
    cout << "Attempting to insert " << value << " into table\n";
    cout << "Hash function generated key " <<  key << endl;
    #endif
    if(table[key]==-1){
        table[key] = value;
        return true;
    }
    #ifdef VERBOSE
    std::cout << "Index produced by key contains data\n";
    #endif
    return false;
}

int HashTable::getElement(int value){
    int key = hashFunc(value);
    return(this->table[key]);
}
