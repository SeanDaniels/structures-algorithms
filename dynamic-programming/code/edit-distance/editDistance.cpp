#include <bits/stdc++.h>
using namespace std;


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
    string a = "kitten";
    string b = "sitting";
    vector<vector<int>> dp(a.size(), vector<int>(b.size()));
    // initialize row 0 and column 0
    // row 0 comes from comparing a[0] with b[0] through b[size - 1]
    cout << "Generating table for number of operations to transform '" << a << "' into '" << b << "'" << endl;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(i==0 && j==0){
                if(a[i]==b[j]) dp[i][j] = 0;
                else dp[i][j] = 1;
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1]+1;
            }
            else if(j==0) dp[i][j] = dp[i-1][j]+1;
            else if(i>0 && j>0) break;
        }
    }
    cout << "Table after initializing: " << endl;
    printVectorOfVectors(dp);
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(j>i)dp[i][j] = dp[i][j-1]+1;
            else if(a[i]==b[j]) dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            else{
              dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
    }
    cout << "Table after all iterations:" << endl;
    printVectorOfVectors(dp);
    cout << "Solution: " << dp[a.size()-1][b.size()-1] << endl;
    return 0;
}
