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

DFS begins by visiting some root or initial node. The edges of this node are placed in the unvisited stack. The first entry of the unvisited stack that is not in the visited stack is then visited. This process is repeated until the unvisisted stack is empty.
