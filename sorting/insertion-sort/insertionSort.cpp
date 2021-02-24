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
    int arrLength = 10, max = 400, checkIndex = 1;
    int values[arrLength];
    int j, holdValue;

    srand(time(0));
    // populate array with random integers
    cout << "--Insertion Sort--" << endl;
    cout << "Before sort: " << endl;
    for(int i = 0; i < arrLength; i++){
        values[i] = rand()%max;
        cout << values[i];
        if(i != 9)
        cout << ",";
        else cout << endl;
    }

    while( checkIndex < arrLength){
        holdValue = values[checkIndex];
        j = checkIndex - 1;
        while( j >= 0 && values[j]>holdValue ){
            values[j+1] = values[j];
            j--;
        }
        values[j+1] = holdValue;
        checkIndex++;
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
