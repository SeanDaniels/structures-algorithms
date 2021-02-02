#ifndef __HASHTABLE_H_
#define __HASHTABLE_H_
#include <iostream>
#include <cstdlib>
#include <ostream>
#include <cmath>

class HashTable{
public:
    int numberOfSlots, occupiedSlots = 0;
    int* table;
    HashTable(int size){
        this->numberOfSlots = size;
        this->table = new int[size];
        for (int i = 0; i < numberOfSlots; i++) {
          table[i] = -1;
        }
    }
    void printTable();
    bool insert(int value);
    int hashFunc(int value);
    int getElement(int value);
    double getMiddleDigits(double value);
    double getLoadFactor() {
      return double(occupiedSlots) / double(numberOfSlots);
    }
};

#endif // __HASHTABLE_H_
