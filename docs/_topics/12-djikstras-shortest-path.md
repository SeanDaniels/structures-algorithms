---
title: "Djikstra's Shortest Path"
permalink: /topics/djikstras-shortest-path/
layout: single
toc: true
---
# Background

The purpose of Djikstra's shortest path algorithm is to determine the shortest distance between the root node and all other nodes. Distance may not be the best term. The value associated with edges of the graph need not be distance. They could be costs associated following a given path, or the number of other entities traversing the given path at the same time. The point is that all of the edges have values associated with them, and the goal is to make it to any given node while minimizing the value associated with getting there. 


# Example Graph

Vertex A: C:20, B:10
Vertex B: A:10, D:50, E:10
Vertex C: A:20, D:20, E:33
Vertex D: B:50, C:20, E:20, F:2
Vertex E: B:10, C:33, D:20, F:1

# Method

The process involves creating a list of unvisited nodes. For this example, the unvisited set includes {A, B, C, D, E, F}. A seperate set of values is also needed for all the weights associated with getting to a given node. This example uses node A as a starting point. The root node will have a value of 0 in this value set, and the remaining values will be set to infinity. The initialized set is {0, inf, inf, inf, inf, inf}. Each node in the unvisited set needs to be visited, starting with node A.

When node A is visited, the weights associated with connected nodes are evaluated. Node A is connected to nodes B and C. The weights associated with B and C are 10 and 20. These values are added to the values set, which now contains {0, 10, 20, inf, inf, inf}. Node A can now be removed from the unvisited set list. 

Next, node B is visited. Node B is connected to A, D, and E. the values are 10, 50, and 10. The value added to the value set will now be the sum of the value associated with getting to B from A and then from getting to D and E from B. The value set now contains {0, 10, 20, *60*, *20*, inf}. 

Next, node C is visited. Node C is connected to A, D, and E. The values are 20, 20, and 33. 
