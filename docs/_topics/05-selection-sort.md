---
title: "Selection Sort"
permalink: /topics/selection-sort/
layout: single
toc: true
---
Selection sort is a sorting method with O(n^2) time complexity.

Selection sort advantages:
- Simple
- In some scenarios, has a performance advantage over more complicated algorithms

Selection sort disadvantages:
- Ineffecient on large lists

Selection sort works by seperating a given list into two sublists. One sublist contains the the original data, and one sublist contains the sorted data. 

The sublist containing the sorted elements is populated by iterating through the unsorted list from a minimum index to the max index of list. The minimum index is updated on each pass through the unsorted list.

Take the following list of integers as an example:
100, 12, 3, 399, 2

The following table shows the sublists after each iteration

| Unsorted             | Sorted               |
|:--------------------:|:--------------------:|
| (100, 12, 3, 399, 2) | ()                   |
| (100, 12, 3, 399)    | (2)                  |
| (100, 12, 399)       | (2, 3)               |
| (100, 399)           | (2, 3, 12)           |
| (399)                | (2, 3, 12, 100)      |
| ()                   | (2, 3, 12, 100, 399) |

