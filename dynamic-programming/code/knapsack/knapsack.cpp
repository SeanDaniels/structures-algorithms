#include <bits/stdc++.h>
using namespace std;

int getMax(int colIndex, int rowIndex,
           unordered_map<int, vector<int>> &thisMap) {
  return 0;
}

int recursiveSolution(vector<int> &values, vector<int> &weights, int availableSpace, int currentIndex){
    // if no space is available, exit
    // if no items remain, exit
    cout << "Entering call with index argument " << currentIndex << endl;
    if(availableSpace <= 0 || currentIndex >= values.size()){
        cout << "Hit base case with index argument " << currentIndex << endl;
        return 0;
    }
    int value1 = 0;
    // weight of current item is less than available space, knapsack can accomodate this item
    if(weights[currentIndex] <= availableSpace){
       // add the value of this item to the solution to set without this item
       cout << "Calling with index argument " << currentIndex + 1 << endl;
       value1 = values[currentIndex] + recursiveSolution(values, weights, availableSpace-weights[currentIndex], currentIndex+1);
    }

    cout << "Calling with index argument " << currentIndex + 1 << endl;
    int value2 = recursiveSolution(values, weights, availableSpace, currentIndex+1);
    cout << "Returning from call with index argument " << currentIndex << endl;
    cout << "Value options: " << value1 << ", " << value2 << endl;
    return max(value1, value2);
}
void printVectorOfVectors(vector<vector<int>> &thisVofV){
    for(auto x : thisVofV){
        for(auto y = x.begin(); y != x.end(); y++){
           cout << *y;
           if(y==x.end()-1)cout << endl;
           else cout << ", ";
        }
    }
}

int main(){
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    vector<int> capacities;
    for(int i = 0; i < 6; i++){
        capacities.push_back(10*i);
    }
    cout << "Capacities: " << endl;
    for(auto x : capacities){
        cout << x;
        if(x==capacities.back()) cout << endl;
        else cout << ", ";
    }
    vector<vector<int>> dp(values.size(), vector<int>(capacities.size()));
    cout << "Un-initialized 0 table:" << endl;
    printVectorOfVectors(dp);

    for(size_t i = 0; i < capacities.size(); i++){
        if(capacities[i]>=weights[0]){
            dp[0][i] = values[0];
        }
    }

    cout << "Initialized table(first row set):" << endl;
    printVectorOfVectors(dp);

    for(size_t i = 1; i < values.size(); i++){
        for(size_t j = 1; j < capacities.size(); j++){
            int valueA = 0, valueB = 0;
            if(weights[i] <= capacities[j]){
                cout << "Current capacity: " << capacities[j] << endl;
                cout << "Weight of this item: " << weights[i] << endl;
                int colIndex = (capacities[j] - weights[i])/10;
                cout << "Using col index: " << colIndex << endl;
                valueA = values[i] + dp[i-1][colIndex];
                cout << "Possible value(a): " << valueA << endl;
            }
            cout << "Generating possible value from index location i,j: " << i-1 << "," << j << endl;
            valueB = dp[i-1][j];
            cout << "Possible value(b): " << valueB << endl;
            dp[i][j] = max(valueA, valueB);
        }
    }

    cout << "Complete table:" << endl;
    printVectorOfVectors(dp);
    return 0;
}
