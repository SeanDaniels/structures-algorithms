#include "hashTable.h"
#include <cstdlib>
using namespace std;
#define TABLE_SIZE 5
int main() {
    HashTable a(5);
    int tempValue, max = 100, successfulInsertions = 0, attemptedInsertions = 5, tableValue[TABLE_SIZE];
    srand(time(0));
    for(int i = 0; i < TABLE_SIZE; i++){
        tempValue = rand()%max;
        tableValue[i] = tempValue;
        if (a.insert(tempValue))
          successfulInsertions++;
    }
    /* Print table information */
    cout << "Table size: " << a.occupiedSlots << endl;
    cout << "Attempted insertions: " << attemptedInsertions << endl;
    cout << "Successful insertions: " << successfulInsertions << endl;
    /* Print table contents */
    a.printTable();
    /* Search through hash table for inserted values */
    for(int i = 0; i < TABLE_SIZE; i++){
        cout << "Searching for value " << tableValue[i] << endl;
        tempValue = a.getElement(tableValue[i]);
        if(tempValue == tableValue[i]){
            cout << "Value found in table" << endl;
        }
        else
            cout << "Value not found in table" << endl;
    }
    return 0;
}
