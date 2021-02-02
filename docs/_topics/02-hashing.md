---
title: "Hashing"
permalink: /topics/hashing/
layout: single
toc: true
---
At it's highest level, hashing is the act of associating some value into some other value. Hashing as a concept occurs in the realm of cryptography, with a heavy focus on developing secure and efficient functions for the association of data with a particular key. That topic is outside of the scope of this project. Here, I will focus on the basics of hashing in order to implement a table. 

An effective hashing function accomplishes meets the following parameters:
- Creates a reasonably unique key for each element
- Computes quickly

To be considered a perfect hash function, the function must generate a unique key for each element of the data set being hashed.

Let's examine a very basic hashing function. Let's say we have a known number of integer elements in a set of data. We could generate a key for each element by doing something like:

``` c++
int key = value % numberOfElements;
```
If the data set contained 15 elements, the following values would produce the following keys:

| Value | Key |
|:-----:|:---:|
| 10    | 5   |
| 16    | 1   |
| 12    | 3   |

Through the process of hashing, a value is associated with some key.


# Hash Table
Hashing is used as a building block for the hash table data structure. A hash table consists of elements indexed by their key. This has an advantage over a simple array in terms of search time. Since the location of the element within the structure is dependent on the element, searching does not need to be iterative or binary. In a perfect hash table, an element can be found in constant time. 

A hash table is built by allocating a fixed amount of contiguous memory, just like an array. When adding elements to the array, a hash function generates a key for the value, and the value is inserted into the allocated space at the index provided by the key. 

If it is known that the allocated memory is greater than the required memory for the elements and the hash function generates a unique key for every value in the set, no further action is needed. If either one of those conditions is not met, a collision policy must be establised. A collision is when the index, produced by the key, points to a location in memory that is occupied with data. There are two primary choices for handling collisions:
- Probing
- Chaining

Probing handles a collision by iterating through the indices of the allocated memory
## Add complexity of hash tables

