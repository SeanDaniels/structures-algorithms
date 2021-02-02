#include "hashTable.h"
#include <math.h>
using std::cout;
using std::endl;
//#define VERBOSE
#define CHAINING
int HashTable::hashFunc(int value){
    return value % this->numberOfSlots;
}

bool HashTable::insert(int value){
    int chainIndex;
    int key = hashFunc(value);

    #ifdef VERBOSE
    cout << "Attempting to insert " << value << " into table\n";
    cout << "Hash function generated key " <<  key << endl;
    #endif
    if(table[key]==-1){
        table[key] = value;
        occupiedSlots++;
        return true;
    }
    #ifdef CHAINING
    else{
        chainIndex = (key+1)%this->numberOfSlots;
        cout << "Start searching at index " << chainIndex << endl;
        while(chainIndex!=key){
            cout << "Search index: " << chainIndex << endl;
            if(table[chainIndex]==-1){
                table[chainIndex] = value;
                occupiedSlots++;
                return true;
            }
            chainIndex=(chainIndex+1)%this->numberOfSlots;
        }
    }
    #endif
    #ifdef VERBOSE
    std::cout << "Index produced by key contains data\n";
    #endif
    return false;
}

int HashTable::getElement(int value){
    int chainIndex;
    int key = hashFunc(value);
    if(table[key]==value)
    return(this->table[key]);
    #ifdef CHAINING
    else{
        chainIndex = (key+1)%this->numberOfSlots;
        cout << "Start searching at index " << chainIndex << endl;
        while(chainIndex!=key){
            cout << "Search index: " << chainIndex << endl;
            if(table[chainIndex]==value){
                return(this->table[chainIndex]);
            }
            chainIndex=(chainIndex+1)%this->numberOfSlots;
        }
        return -1;
    }
    #endif
}

double HashTable::getMiddleDigits(double value){
   double numberOfDigits;
   int loopCounter, startPosOfMiddleDig, tempDigit, singleDigit, mostSigDig, resultOfMod = 0;
   // determine number of digits
   // What power do you need to raise 10 to in order to create the value?
   // round numbers for 0, 10, 100, etc, but that's it, so take the floor and add 1
   // for example, log10 of 123 = 2.dontCare. Slam that down and add 1 to get 3, which is the number of digits
   numberOfDigits = floor(log10(value))+1;//ceil(log10(value));
   loopCounter = numberOfDigits;
   startPosOfMiddleDig = floor(numberOfDigits/2);
   cout << "Number of digits: " << numberOfDigits << endl;
   cout << "Start pos of middle digits " << startPosOfMiddleDig << endl;
   while(loopCounter--){
       cout << "Counter: " << loopCounter << endl;
       tempDigit = value / pow(10, numberOfDigits);
       singleDigit = tempDigit % 10;
       cout << "Temp digit(s): " << tempDigit << endl;
       cout << "Single digit: " << singleDigit << endl;
   } 
   return numberOfDigits;
}

void HashTable::printTable() {
  std::cout << "Key|Value\n";
  for (int i = 0; i < numberOfSlots; i++) {
    cout << i << " | ";
    if (table[i] == -1)
      cout << "EMPTY" << endl;
    else
      cout << table[i] << endl;
  }
}
