#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
        int numberOfNodes;
        vector<vector<int>> adjacencyList, cycleList;
        vector<int> visitedTable, unvisited, visitedSet;
        vector<bool> boolVisited;

        Graph(int nodes){
            numberOfNodes = nodes;
            adjacencyList = vector<vector<int>> (nodes, vector<int>(nodes));
            for(int i = 0; i < numberOfNodes; i++){
                visitedTable.push_back(0);
                boolVisited.push_back(false);
            }
        }

        void addEdge(int src, int dst){
          adjacencyList[src][dst] = 1;
        }

        void printAdjacencyList(){
            for(auto x : adjacencyList){
                for(auto y = x.begin(); y != x.end(); y++){
                cout << *y;
                if(y==x.end()-1)cout << endl;
                else cout << ", ";
                }
            }
        }

        vector<int> *getAdjacency(int thisNode){
            return &adjacencyList[thisNode];
        }

        bool isVisited(int node){
            auto found = find(visitedSet.begin(), visitedSet.end(), node);
            if(found != visitedSet.end()) return true;
            return false;
        }

        void dfs_b(int targetNode){
            boolVisited[targetNode] = true;
            cout << targetNode << " ";
            vector<int> currentNodeAdjacenyList = adjacencyList[targetNode];
            vector<int> discovered;
            for(auto it = currentNodeAdjacenyList.begin(); it != currentNodeAdjacenyList.end(); ++it){
                cout << *it << ",";
                if(*it != 0 && boolVisited[*it]==false){
                    dfs_b(*it);
                }
            }
        }

        void dfs_a(int targetNode){

            if(isVisited(targetNode)){
                cout << "Node " << targetNode << " has already been visited" << endl;
                return;
            }

            else{
                cout << "Node " << targetNode << " has not been visited" << endl;
                // add node to adjacency list
                vector<int> tempAdjacencyList = adjacencyList[targetNode];
                cout << "Adding edges of current node to 'unvisited' list" << endl;
                // add edges of current node to unvisited list (assume nodes aren't visited)
                for(int i = 0; i < numberOfNodes; i++){
                    if(tempAdjacencyList[i]!=0) unvisited.push_back(i);
                }
                cout << "Adding node " << targetNode << " to 'visited' list" << endl;
                // add current node to list of visited nodes
                visitedSet.push_back(targetNode);
                // iterate through this node's edges
                while(unvisited.size()>0){
                    cout << "Visiting back node of 'unvisited' list" << endl;
                    // get next node
                    int next = unvisited.back();
                    cout << "Removing back node of 'unvisited' list" << endl;
                    // pop next node from unvisited list
                    unvisited.pop_back();
                    // visit this next node
                    dfs_a(next);
                }

            }
        }

        bool cycleUtility(int targetNode, bool visited[], bool *recStack) {
          if (visited[targetNode] == false) {
            visited[targetNode] = true;
            recStack[targetNode] = true;
            for (auto it = adjacencyList[targetNode].begin(); it != adjacencyList[targetNode].end(); it++) {
              if (!visited[*it] && cycleUtility(*it, visited, recStack)) {
                return true;
              } else if (recStack[*it]){
                return true;
              }
            }
          }
          recStack[targetNode] = false;
          return false;
        }

        bool hasCycle(){
            bool *visited = new bool[numberOfNodes];
            bool *recStack = new bool[numberOfNodes];
            for(int i = 0; i < numberOfNodes; i++){
                visited[i] = false;
                recStack[i] = false;
            }
            for(int i = 0; i < numberOfNodes; i++){
                cout << numberOfNodes << endl;
                cout << "Checking for cycle with node " << i << endl;
                if(cycleUtility(i, visited, recStack)) return true;
            }
            return false;
        }

};

int main(){

    // create graph with 5 nodes (node 1 through node 5)
    // add edge from node 1 to node 5
    /* [Node 0] - [Node 1] - [Node 2]
                  /      \           //
           [Node 3] - [Node 4]       */

    Graph myGraph(5);
    myGraph.addEdge(0,1);
    myGraph.addEdge(1,2);
    myGraph.addEdge(1,3);
    myGraph.addEdge(1,4);
    myGraph.addEdge(3,4);
    myGraph.addEdge(4,0);
    myGraph.printAdjacencyList();
    myGraph.dfs_b(0);
    return 0;
}
