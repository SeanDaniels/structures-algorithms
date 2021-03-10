---
title: "Dynamic Programming"
permalink: /topics/dynamic-programming/
layout: single
toc: true
---
Dynamic programming is a description of a programming method which uses previously computed results to obtain current results. 

Any solution that depends upon a previous solution, or could be returned by a formulaic alteration to an existing solution, is a candidate for dynamic programming. A common example is a function to determine the nth value of the fibonacci sequence. 

The fibonacci sequence is the set of numbers whose values are determined by the sum of the previous two numbers in the set, excluding the first two numbers in the set. For example, the first eight numbers of the fibonacci sequence are:

| 0 | 1 | 1 | 2 | 3 | 5 | 8 | 13  |

This set is frequently used as a primer for recursive functions. When solving for the nth number recursively, the solution looks like:

```c++ 
int fibb(int pos){
    if(pos==0)return 0;
    if(pos==1)return 1;
    return fibb(pos-1) + fibb(pos-2)
}
```
The 0th and 1st elements of the fibonacci sequence are base cases, set at 0 and 1. 

This function would will call recursively until either of the base cases are met. The function call graph would look like:

![Fibb Call](/structures-algorithms/assets/images/fibb-call-graph.jpg)

The repeated calculations that produce the same result can be costly. All recursive functions suffer from this potential limitation. 

The results of the calculations could instead be stored in an array, saving some of the overhead. It should be noted that while this can save some performance overhead, dynamic programming does increase the storage overhead of a routine. 

Solving the fibonacci sequence with dynamic programming would look like the following:
```c++
int dp[MAX];
void initDP{
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < MAX; i++){
    // init dp array to negative one, indicating this solution hasn't been generated yet
        dp[i] = -1;
    }
}
int fibb(int pos){
    if(dp[pos]==-1){
        return dp[pos] = fibb(pos-1) + fibb(pos-2);
    }
    else return dp[pos];
}
```
This function still works recursively, but removes the need to calculate the same solution multiple times.

Dynamic programming comes in two main flavors. They are top down and bottom up.

## Top down

The fibonacci function is an example of a top down dynamic programming. The function works from the current position towards the base case, generating any new solutions as needed. This is very similar to the recursive solution, except the return value is saved for later use.

The saving of the return value is known as memoization.

## Bottom up
Alternatively, dynamic programming solutions can be derived from the bottom up. Instead of working towards the base case, the function can start at the base case and build towards the desired case. This is an iterative approach. Using the fibonacci sequence again, a bottom up approach would look like:
```c++
int dp[MAX];
dp[0] = 0;
dp[1] = 1;
for(int i = 2; i < desiredIndex; i++){
    fibb[i] = fibb[i-2] + fibb[i-1];
}
```
