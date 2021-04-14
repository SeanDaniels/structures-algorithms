#include <bits/stdc++.h>
using namespace std;
#define INF -1
#define NUM_NODES 6
void printVectorOfVectors(vector<vector<int>> &thisVofV){
    for(auto x : thisVofV){
        for(auto y = x.begin(); y != x.end(); y++){
           cout << *y;
           if(y==x.end()-1)cout << endl;
           else cout << ", ";
        }
    }
}

int findNextMinimumDistance(vector<int> &distanceVector, vector<bool> &pathSet){
    // initialize minimum value to large number
    int min = INT_MAX;
    int minIndex;
    // check for each node in shortest path set
    for(int i = 0; i < NUM_NODES; i++){
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

void printShortestPath(vector<int> &distanceVector){
    cout << "Node\t\t Distance from source\n";
    for(int i = 0; i < distanceVector.size(); i++){
        cout << i << setw(6) << " \t\t " << distanceVector[i] << endl;
    }
}

void doDijkstra(vector<vector <int>> &thisGraph, int srcIndex){
    vector<int> distanceVector;
    vector<bool> pathSet;
    for(int i = 0; i < NUM_NODES; i++){
        distanceVector.push_back(INT_MAX);
        pathSet.push_back(false);
    }
    distanceVector[srcIndex] = 0;
    // initial distanceVector = {0, int_max, int_max, int_max, int_max, int_max}
    // initial pathSet = { false, false, false, false, false, false }
    for(int j = 0; j < NUM_NODES - 1; j++){
        // find shortest path to un visited nodes
        int shortestIndex = findNextMinimumDistance(distanceVector, pathSet);
        // update visited node list
        pathSet[shortestIndex] = true;

        for(int k = 0; k < NUM_NODES; k++){
            // !pathSet[k] -> this node hasn't been visited
            // thisGraph[shortestIndex][k] -> is there a path from the current node to the unvisited node
            // distanceVector[shortestIndex] != INT_MAX -> a shortest path has been determined for the current node
            // distanceVector[shortestIndex] + thisGraph[shortestIndex][k] < distanceVector[k] -> the value to get the current node + the value to get from current node to a given node is less than the value already contained in the distanceVector vector
            if(!pathSet[k] && thisGraph[shortestIndex][k] && distanceVector[shortestIndex] != INT_MAX && distanceVector[shortestIndex] + thisGraph[shortestIndex][k] < distanceVector[k])
                distanceVector[k] = distanceVector[shortestIndex] + thisGraph[shortestIndex][k];
        }
    }

    printShortestPath(distanceVector);

}

int main(){
    // 6 nodes: A, B, C, D, E, F
    // Edges: (A,B), (A,C), (B,D), (B,E), (C,D), (C,E), (D,F), (E,F)
    // A: 0, 1, 1, 0, 0, 0
    // B: 1, 0, 0, 1, 1, 0
    // C: 1, 0, 0, 1, 1, 0
    // D: 0, 1, 1, 0, 0, 1
    // E: 0, 1, 0, 1, 0, 1
    // F: 0, 0, 0, 0, 1, 1
    vector<vector<int>> edgeList(NUM_NODES, vector<int>(NUM_NODES));
    // Node A
    edgeList[0] = {0, 10, 20, 0, 0, 0};
    // Node B
    edgeList[1] = {10, 0, 0, 50, 10, 0};
    // Node C
    edgeList[2] = {20, 0, 0, 20, 33, 0};
    // Node D
    edgeList[3] = {0, 50, 20, 0, 20, 2};
    // Node E
    edgeList[4] = {0, 10, 33, 20, 0, 1};
    // Node F
    edgeList[5] = {0, 0, 0, 0, 2, 1};

    doDijkstra(edgeList, 0);
    return 0;

}
