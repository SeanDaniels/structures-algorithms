#ifndef __HASHTABLE_H_
#define __HASHTABLE_H_
#include <iostream>
#include <cstdlib>
#include <ostream>

class HashTable{
public:
    int tableSize;
    int* table;
    HashTable(int size){
        this->tableSize = size;
        this->table = new int[size];
        for (int i = 0; i < tableSize; i++) {
          table[i] = -1;
        }
    }
    void printTable(){
        std::cout << "Printing table\n";
        for (int i = 0; i < tableSize; i++) {
            std::cout << "Key: " << i << std::endl;
            if(table[i]==-1)
                std::cout << "EMPTY\n";
            else std::cout << table[i] << std::endl;

        }
    }
    bool insert(int value);
    int hashFunc(int value);
    int getElement(int value);
};

#endif // __HASHTABLE_H_
