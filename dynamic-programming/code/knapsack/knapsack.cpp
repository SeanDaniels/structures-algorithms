#include <bits/stdc++.h>
using namespace std;

int getMax(int colIndex, int rowIndex,
           unordered_map<int, vector<int>> &thisMap) {
  return 0;
}

int main(){
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    vector<vector<int>> table;
    unordered_map<int, int> valueMap;
    int granularity = 10, maxWeight = 50;
    int numberOfColumns = maxWeight/granularity;
    int numberOfRows = values.size()-1;
    vector<int> tempValues, tempMax;
    for(int i = 0; i < values.size(); i++){
        auto mapIterator = valueMap.find(values[i]);
        if(mapIterator==valueMap.end()){
            valueMap.insert({values[i], weights[i]});
        }
    }

    tempValues.push_back(values[0]);
    int tempWeight = valueMap.find(values[0])->second;
    for(int i = 0; i < numberOfColumns; i++){
        int currWeight = granularity*i;
        if(currWeight < tempWeight) tempMax.push_back(0);
        else if(currWeight)
    }


}
