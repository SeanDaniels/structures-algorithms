#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
        int numberOfNodes;
        vector<vector<int>> adjacencyList;

        Graph(int nodes){
            numberOfNodes = nodes;
            adjacencyList = vector<vector<int>> (nodes, vector<int>(nodes));

        }

        void addEdge(int src, int dst){
          adjacencyList[src-1][dst-1] = 1;
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

        void dfs(){
            vector<int> visited, unvisited, tempAdj;
            int visiting = 0;
            visited.push_back(visiting);
            tempAdj = adjacencyList[visiting];
            while(visited.size() < this->numberOfNodes){
                for(int i = 0; i < this->numberOfNodes; i++){
                    if(tempAdj[i] != 0){
                        unvisited.push_back(tempAdj[i]);
                    }
                }
            }

        }
};

int main(){

    // create graph with 5 nodes (node 1 through node 5)
    // add edge from node 1 to node 5
    /* [Node 1] - [Node 2] - [Node 3]
                  /      \           //
           [Node 4] - [Node 5]       */

    Graph myGraph(5);
    myGraph.addEdge(1,2);
    myGraph.addEdge(2,3);
    myGraph.addEdge(2,4);
    myGraph.addEdge(2,5);
    myGraph.addEdge(4,5);
    myGraph.printAdjacencyList();
    myGraph.dfs();
    return 0;
}
