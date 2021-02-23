#include <iostream>
#include <cstdlib>

using namespace std;

void mySwap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

int main(int argc, char *argv[]) {
    int arrLength = 10, max = 400;
    int values[arrLength];
    srand(time(0));
    // populate array with random integers
    cout << "Before sort: " << endl;
    for(int i = 0; i < arrLength; i++){
        values[i] = rand()%max;
        cout << values[i];
        if(i != 9)
        cout << ",";
        else cout << endl;
    }


    for(int i = 0; i < arrLength-1; i++){
        // assume minimum index is i's current position
        int minIndex = i;
        // iterate from arr[i+1] to arr[n]
        for(int ii = i+1; ii < arrLength; ii++){
            // find the lowest value
            if(values[ii] < values[minIndex]){
                minIndex = ii;
            }

        }

        // if lowest value is not located at assumed index, swap lowest value and value at assumed index
        if(minIndex != i){
            mySwap(values[i], values[minIndex]);
        }
    }

    cout << "After sort: " << endl;
    for(int i = 0; i < arrLength; i++){
        cout << values[i];
        if(i != 9)
        cout << ",";
        else cout << endl;
    }

    return 0;
}
