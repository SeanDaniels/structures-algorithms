#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void mergeArray(int a[], int b[], int begin, int middle, int end){
    int i = begin, j = middle;
    for(int k = begin; k < end; k++){
        if( i < middle && ( j >= end || (a[i] <= a[j]) ) ){
            b[k] = a[i];
            i = i + 1;
        }
        else{
            b[k] = a[j];
            j = j + 1;
        }
    }
    cout << "After merge: " << endl;
    for(int k = begin; k < end; k++){
        cout << b[k] << ", ";
    }
    cout << endl;
}

void splitArray(int a[], int b[], int begin, int end){
    for(int i = begin; i < end; i++ ){
        cout << a[i] << ", ";
    }
    cout << endl;
    if((end-begin)<=1){
      // cout < "Begin: " << begin << " End: " << end << endl;
      return;
    }
    int middle = (begin + end)/2;
    // cout << "Begin: " << begin << " Middle: " << middle << " End: " << end << endl;
    splitArray(a, b, begin, middle);
    splitArray(a, b, middle, end);
    mergeArray(b, a, begin, middle, end);
}

void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
    for(int k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}

void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
    int i = iBegin, j = iMiddle;

    // While there are elements in the left or right runs...
    for (int k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
    if(iEnd - iBegin <= 1)                       // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int A[], int B[], int n)
{
    CopyArray(A, 0, n, B);           // one time copy of A[] to B[]
    TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

int main(int argc, char *argv[]) {
    int a[6] =  { 5, 2, 1, 3, 4, 6};
    int b[6];
    TopDownMergeSort(a, b, 6);
    for(int i = 0; i < 6; i++){
        cout << b[i] << ", ";
    }
    cout << endl;
    return 0;
}
