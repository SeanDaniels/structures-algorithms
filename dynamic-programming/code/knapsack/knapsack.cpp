#include <bits/stdc++.h>
using namespace std;


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
    // initialize a capacities vector
    // this needs to be fixed, the goal is to be able to pass a weight as an argument
    for(int i = 0; i < 6; i++){
        capacities.push_back(10*i);
    }

    cout << "Capacities: " << endl;
    vector<vector<int>> dp(values.size(), vector<int>(capacities.size()));
    cout << "Un-initialized 0 table:" << endl;
    printVectorOfVectors(dp);
    // initialize first row of table
    // this corresponds with only being able to pick the first item in the list
    for(size_t i = 0; i < capacities.size(); i++){
        if(capacities[i]>=weights[0]){
            dp[0][i] = values[0];
        }
    }

    cout << "Initialized table(first row set):" << endl;
    printVectorOfVectors(dp);

    // i,j = row,col
    // start at 1 for both -> row 0 has already been set (single item case), col 0 has already been set (0 capacity case)
    for(size_t i = 1; i < values.size(); i++){
        int currentItemWeight = weights[i];
        for(size_t j = 1; j < capacities.size(); j++){
            int valueA = 0, valueB = 0, currentKnapsackCapacity = capacities[j];
            if(currentItemWeight <= currentKnapsackCapacity){
                // this is only valid for this weight/capacity relationship.
                int colIndex = (currentKnapsackCapacity - currentItemWeight)/10;
                // include this item
                // the value will be this items value + the maximum determined value at this capacity prior to this item
                valueA = values[i] + dp[i-1][colIndex];
            }
            // exclude this item
            valueB = dp[i-1][j];
            dp[i][j] = max(valueA, valueB);
        }
    }

    cout << "Complete table:" << endl;
    printVectorOfVectors(dp);
    return 0;
}
