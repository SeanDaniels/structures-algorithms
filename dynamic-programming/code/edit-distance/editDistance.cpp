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
    for(int i = 0; i < b.size(); i++){
        if(i==0){
            if(a[0]==b[0]){
               dp[0][0] = 0;
            }
            else{
                dp[0][0] = 1;
            }
        }
        else{
            dp[0][i] = dp[0][i-1] + 1;
        }
    }
    for(int i = 1; i < a.size(); i++){
        dp[i][0] = dp[i-1][0] + 1;
    }
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1];
            else{
                if(i>j) dp[i][j] = dp[i][j-1] - 1;
                else if(j>i)dp[i][j] = dp[i][j-1] + 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    printVectorOfVectors(dp);
    cout << "Solution: " << dp[a.size()-1][b.size()-1] << endl;
    return 0;
}
