#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
        int numberOfNodes;
        vector<vector<int>> adjacencyList;
        vector<int> visitedTable, unvisited, visitedSet;

        Graph(int nodes){
            numberOfNodes = nodes;
            adjacencyList = vector<vector<int>> (nodes, vector<int>(nodes));
            for(int i = 0; i < numberOfNodes; i++){
                visitedTable.push_back(0);
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

        void dfs(int targetNode){

            if(isVisited(targetNode)){
                return;
            }

            if(visitedTable[targetNode] == 0){
                cout << "Node " << targetNode << " has not been visited" << endl;
                vector<int> tempAdjacencyList = adjacencyList[targetNode];
                cout << "Adding edges of current node to 'unvisited' list" << endl;
                for(int i = 0; i < numberOfNodes; i++){
                    if(tempAdjacencyList[i]!=0) unvisited.push_back(i);
                }
                cout << "Adding node " << targetNode << " to 'visited' list" << endl;
                visitedTable[targetNode] = 1;
                visitedSet.push_back(targetNode);
                cout << "Printing size of visited set:" << endl;
                while(unvisited.size()>0){
                    cout << "Visiting back node of 'unvisited' list" << endl;
                    int next = unvisited.back();
                    cout << "Removing back node of 'unvisited' list" << endl;
                    unvisited.pop_back();
                    dfs(next);
                }
            }
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
    myGraph.printAdjacencyList();
    myGraph.dfs(0);
    cout << "Printing visited set:" << endl;
    for(auto x : myGraph.visitedSet){
        cout << x;
        if(x==myGraph.visitedSet.back()){
            cout << endl;
        }
        else{
            cout << ",";
        }

    }
    cout << endl;
    return 0;
}
