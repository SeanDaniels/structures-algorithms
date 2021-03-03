#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merge(int source[], int begin, int middle, int end, int destination[])
{
    int i = begin, j = middle;

    // While there are elements in the left or right runs...
    for (int k = begin; k < end; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < middle && (j >= end || source[i] <= source[j])) {
            destination[k] = source[i];
            i = i + 1;
        } else {
            destination[k] = source[j];
            j = j + 1;
        }
    }
}

void splitMerge(int b[], int begin, int end, int a[])
{
    if(end - begin <= 1)
        return;
    
    int middle = (end + begin) / 2;
    splitMerge(a, begin,  middle, b);
    splitMerge(a, middle,    end, b);
    //merge the resulting runs from array B[] into A[]
    merge(b, begin, middle, end, a);
}
void copyArray(int a[], int begin, int end, int b[]){
    for(int i = begin; i < end; i++){
        b[i] = a[i];
    }
}
// Array A[] has the items to sort; array B[] is a work array.
void copySplitMerge(int a[], int b[], int n)
{
    copyArray(a, 0, n, b);           // one time copy of A[] to B[]
    splitMerge(b, 0, n, a);   // sort data from B[] into A[]
}

int main(int argc, char *argv[]) {
    cout << "--Merge Sort--" << endl;
    int a[6] =  { 5, 2, 1, 3, 4, 6};
    cout << "Original array:" << endl;
    for(int i = 0; i < 6; i++){
        cout << a[i] << ", ";
    }
    cout << endl;
    int b[6];
    copySplitMerge(a, b, 6);
    cout << "Sorted array:" << endl;
    for(int i = 0; i < 6; i++){
        cout << b[i] << ", ";
    }
    cout << endl;
    return 0;
}
