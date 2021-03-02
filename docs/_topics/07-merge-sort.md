---
title: "Merge Sort"
permalink: /topics/merge-sort/
layout: single
toc: true
---

Merge sort is a comparison based sorting algorithm, utilizing a divide and conquer method. Merge sort operates is O(n log n) run time, while both insertion sort and selection sort have O(n^2) run times.

| Merge Sort                  |   |
|:---------------------------:|:-:|
| Best-case performance       |   |
| Worst-case performance      |   |
| Average performance         |   |
| Worst-case space complexity |   |


## Algorithm

- Divide unsorted list into n sublists, each containing one element
- Repeatedly merge sublists to produce new sorted sublists until only one sublist remains

## High Level Description

Merge sort operates on the principle that a list with a single element is considered sorted. To that end, the merge sort algorithm repeatedly divides an array until it has arrived at a sublist with a single element. The single elements are compared and merged, until a sorted array is generated which contains all of the origial elements. 

