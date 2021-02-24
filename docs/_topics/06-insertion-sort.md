---
title: "Insertion Sort"
permalink: /topics/insertion-sort/
layout: single
toc: true
---
Insertion sort also has O(n^2) time complexity

Insertion sort advantages:
- More efficient in practice than other quadratic search functions, like selection sort

Insertion sort disadvantages:
- Inefficient on large lists

## How it works

Insertion sort works by checking behind the current index of the list while iterating. For each element in the list, the search checks from the curent elements index backwards until a value is found that is not greater than the current the element. 

While values are found that are greater than the current element, the larger elements are pushed forward.

The search begins at 2nd element of list, the element at index 1. The interior loop of the search begins at the element directly preceeding the element associated with current iteration of the search.

## Pseudo Code
```c++
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
```
