---
title: "Djikstra's Shortest Path"
permalink: /topics/djikstras-shortest-path/
layout: single
toc: true
---
# Background

The purpose of Djikstra's shortest path algorithm is to determine the shortest distance between the root node and all other nodes. Distance may not be the best term. The value associated with edges of the graph need not be distance. They could be costs associated following a given path, or the number of other entities traversing the given path at the same time. The point is that all of the edges have values associated with them, and the goal is to make it to any given node while minimizing the value associated with getting there. 


# Example Graph

Vertex A: B:10, C:20
Vertex B: A:10, D:50, E:10
Vertex C: A:20, D:20, E:33
Vertex D: B:50, C:20, E:20, F:2
Vertex E: B:10, C:33, D:20, F:1

# Method

The process involves creating a list of unvisited nodes. For this example, the unvisited set includes {A, B, C, D, E, F}. A seperate set of values is also needed for all the weights associated with getting to a given node. This example uses node A as a starting point. The root node will have a value of 0 in this value set, and the remaining values will be set to infinity. The initialized set is {0, inf, inf, inf, inf, inf}. Each node in the unvisited set needs to be visited, starting with node A.

When node A is visited, the weights associated with connected nodes are evaluated. Node A is connected to nodes B and C. The weights associated with B and C are 10 and 20. These values are added to the values set, which now contains {0, 10, 20, inf, inf, inf}. Node A can now be removed from the unvisited set list. 

Next, node B is visited. Node B is connected to A, D, and E. the values are 10, 50, and 10. The value added to the value set will now be the sum of the value associated with getting to B from A and then from getting to D and E from B. The value set now contains {0, 10, 20, *60*, *20*, inf}. 

Next, node C is visited. Node C is connected to A, D, and E. The values are 20, 20, and 33. 

Here is the code to determine the next minimum distance to process

```c++
int findNextMinimumDistance(vector<int> &distanceVector, vector<bool> &pathSet){
    // initialize minimum value to large number
    int min = INT_MAX;
    int minIndex;
    // check for each node in shortest path set
    for(int i = 0; i < NUM_VERTICES; i++){
        // if node does not exist in the shortest path set and the distance value for this node is less than the current minimum value
        if(pathSet[i] == false && distanceVector[i] <= min){
            // updated minimum to this value
            min = distanceVector[i];
            // update minimum index to this index
            minIndex = i;
        }
    }
    return minIndex;
}
```
Initially, the 'pathSet' vector contains a false entry for each node. The 'distanceVector' vector contains 0 for the first node, and a set max value for all other nodes.

pathSet = { false, false, false, false, false, false }

distanceVector = { 0, max, max, max, max, max }

the function iterates through all values in distance vector and path vector. If the path vector contains a false value at a given index, the node has not been visited. If the 'distanceVector' entry is less than the max value, it means that a minimum value path has been determined for this node.

Again, the first node processed is node 0, which is the only position in the distance vector that contains a value less than the max value, forcing it to be processed first. The initial call to this function returns the index of 0, which corresponds to node A.

As the graph is processed, this function will chose the next node to process based on the value associated with that node in the distance vector.

Here is the code that processed the nodes of the graph:
```c++
for(int j = 0; j < NUM_NODES - 1; j++){
    // find shortest path to un visited nodes
    int shortestIndex = findNextMinimumDistance(distanceVector, pathSet);
    // update visited node list
    pathSet[shortestIndex] = true;

    for(int k = 0; k < NUM_NODES; k++){
        if(!pathSet){
            if(thisGraph[shortestIndex][k]){
                if(distanceVector[shortestIndex] != INT_MAX){
                    if(distanceVector[shortestIndex] + thisGraph[shortestIndex][k] < distanceVector[k])
                        distanceVector[k] = distanceVector[shortestIndex] + thisGraph[shortestIndex][k];
                }
            }
        }
}
```


The first step is to find the next shortest path index in line. After determining which node will be visited next, the 'pathSet' value for the next node is set to true, which removes it from consideration when processing the other nodes.

After the shortest index is set, all the nodes of the graph are considered. In order for the distance vector to be updated, a few requirements need to be met.

First, the node can't have already been processed by the algorithm. If the pathSet value for a given node is true, the distance vector entry for this node has already been determined.

The next condition is that an edge from the current node to a given a node exists. If it doesn't, there is no use in considering it for a shortest path candidate.

Additionally, the shortest path to the current node must have already been computed in order for the paths computed with respect the current node to have any meaning. 

Finally, if the distance vector entry for the current node plus the path to the next node is less than the current recorded shortest distance for the next node, the distance value is updated
