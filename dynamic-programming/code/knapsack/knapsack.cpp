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

int main(){
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
<<<<<<< HEAD
=======
    cout << recursiveSolution(values, weights, 50, 0) << endl;
    // vector<vector<int>> table;
    // unordered_map<int, int> valueMap;
    // int granularity = 10, maxWeight = 50;
    // int numberOfColumns = maxWeight/granularity;
    // int numberOfRows = values.size()-1;
    // vector<int> tempValues, tempMax;
    // for(int i = 0; i < values.size(); i++){
    //     auto mapIterator = valueMap.find(values[i]);
    //     if(mapIterator==valueMap.end()){
    //         valueMap.insert({values[i], weights[i]});
    //     }
    // }

    // tempValues.push_back(values[0]);
    // int tempWeight = valueMap.find(values[0])->second;
    // for(int i = 0; i < numberOfColumns; i++){
    //     int currWeight = granularity*i;
    //     if(currWeight < tempWeight) tempMax.push_back(0);
    //     else if(currWeight)
    // }
>>>>>>> cd01d8d6e0c7e09260e2c2456b55b12b2f1d752b


}
