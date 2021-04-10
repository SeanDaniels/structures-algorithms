---
title: "Djikstra's Shortest Path"
permalink: /topics/djikstras-shortest-path/
layout: single
toc: true
---
# Background

The purpose of Djikstra's shortest path algorithm is to determine the shortest distance between the root node and all other nodes. Distance may not be the best term. The value associated with edges of the graph need not be distance. They could be costs associated following a given path, or the number of other entities traversing the given path at the same time. The point is that all of the edges have values associated with them, and the goal is to make it to any given node while minimizing the value associated with getting there. 

This example will use a non-directed graph. 

# Example Graph

Vertex A: C:20, B:10
Vertex B: A:10, D:50, E:10
Vertex C: A:20, D:20, E:33
Vertex D: B:50, C:20, E:20, F:2
Vertex E: B:10, C:33, D:20, F:1
