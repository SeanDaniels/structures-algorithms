---
title: "Graph Traversal"
permalink: /topics/graph-traversal/
layout: single
toc: true
---
# Concept

Graph traversal is the method with which a graph is iterated through. There are two primary methods: Depth First Search (DFS) and Breadth First Search (BFS).

# DFS

DFS uses a stack to store the nodes that are being visited. Edges that lead to an unvisited node are called 'discovery edges'.

There are both iterative and recursive methods for performing a depth first search on graph. This description outlines a recursive approach.

The graph is represented using a vector of vectors. Each node has a vector, and each node's vector indicates if there is an edge from the given node to the other nodes in the graph. 

The following graph is used for this example:

![Initial Graph](/structures-algorithms/assets/images/gt-initial.jpg)

When laid out as a table, this is how the example graph is represented:

|   | 0 | 1 | 2 | 3 | 4 |
|:-:|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 1 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 | 1 | 1 |
| 2 | 0 | 0 | 0 | 0 | 0 |
| 3 | 0 | 0 | 0 | 0 | 1 |
| 4 | 1 | 0 | 0 | 0 | 0 |

DFS works by recursively visiting the nodes that are connected to the current node. 

If DFS was executed on node 0:

![Step One](/structures-algorithms/assets/images/graph-traversal/gt-1.jpg)

The adjacency list of node 0 is iterated through. Each entry in the adjacency list that isn't set to 0 is checked against a list of nodes that have been visited. If the node has not been visited, the process is repeated on the unvisited node. 

Unvisited: 1, 2, 3, 4
Adjacency list of node 0: 0, 0, 1, 0, 0

Edge from node 0 to node 1, node 1 is not visited. Visit node 1.

![Step Two](/structures-algorithms/assets/images/graph-traversal/gt-2.jpg)

Unvisited: 2, 3, 4
Adjacency list of node 1: 0, 0, 1, 1, 1

Edge from node 1 to node 2, node 2 is not visited. Visit node 2.

![Step Three](/structures-algorithms/assets/images/graph-traversal/gt-3.jpg)

Unvisited: 3, 4
Adjacency list of node 2: 0, 0, 0, 0, 0

No edges exiting node 2, return to adjacency list of node 1.

![Step Four](/structures-algorithms/assets/images/graph-traversal/gt-4.jpg)

Unvisited: 3, 4

Edge from node 1 to node 3, node 3 has not been visited. Visit node 3.

![Step Five](/structures-algorithms/assets/images/graph-traversal/gt-5.jpg)

Unvisited: 4
Adjacency list of node 3: 0, 0, 0, 0, 1

Edge from node 3 to node 4, node 4 has not been visited. Visit node 4.


![Step Six](/structures-algorithms/assets/images/graph-traversal/gt-6.jpg)

Unvisited: -
Adjacency list of node 4: 1, 0, 0, 0, 0

Edge from node 4 to node 0, node 0 has been visted. No other edges from node 4, return to node 3's adjacency list.

No other edges from node 3. Return to node 1's adjacency list


![Step Seven](/structures-algorithms/assets/images/graph-traversal/gt-7.jpg)

Edge from node 1 to node 4. Node 4 has been visted. No other edges from node 1. Return to node 0. 

No other edges from node 0, return.

![Step Eight](/structures-algorithms/assets/images/graph-traversal/gt-8.jpg)
