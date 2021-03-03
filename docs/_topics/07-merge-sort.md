---
title: "Merge Sort"
permalink: /topics/merge-sort/
layout: single
toc: true
---

Merge sort is a comparison based sorting algorithm, utilizing a divide and conquer method. Merge sort operates in O(n log n) run time, while both insertion sort and selection sort have O(n^2) run times. The reason that merge sort operates in O(n log n) time is because the number of divisions necessary for an n element list is logarithmically proportional to the number of elements. The actions necessary to complete the merge sort are as follows:

- Divide each list/sublist until each element is contained within it's own sublist
- Compare element(s) in sublist a to element(s) in sublist b
- Merge sublists

The number of comparisons per sublist is proportional to the number of elements in the sublist, producing the 'n' factor of O(*n* log n). Since comparisons happen between sublists, and the number of sublists is the result of continually halving the original list, the amount of comparisons executed is only logarithmically proportional to the number of elements in original list, producing the log n factor of O(n *log n*).

| Merge Sort                  |   |
|:---------------------------:|:-:|
| Best-case performance       |   |
| Worst-case performance      |   |
| Average performance         |   |
| Worst-case space complexity |   |


## Algorithm

- Divide unsorted list into sublists, each containing one element
- Compare elements in sublist a to element in sublist b 
- Repeatedly merge sublists to produce new sorted sublists until only one sublist remains

## High Level Description

Merge sort operates on the principle that a list with a single element is considered sorted. To that end, the merge sort algorithm repeatedly divides an array until it has arrived at a sublist with a single element. The single elements are compared and merged, until a sorted array is generated which contains all of the origial elements. 

## Example

![Example Sort](/structures-algorithms/assets/images/merge-sort.png)
