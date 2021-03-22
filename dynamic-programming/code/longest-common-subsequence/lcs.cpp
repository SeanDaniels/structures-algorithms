#include <bits/stdc++.h>
using namespace std;

pair<int, string> naiveApproach(string& s1, string& s2){
    string matchString, temp;
    int oldMax, longestMatch = 0;
    map<string, string> subStrings;
    for(size_t i = 0; i < s1.length(); i++){
        for(size_t j = i+1; j <= s1.length(); j++){
            temp = s1.substr(i, j-i);
            auto it = subStrings.find(temp);
            if(it == subStrings.end()){
                subStrings.insert({temp, temp});
            }
        }
    }
    for(size_t i = 0; i < s2.length(); i++){
        for(size_t j = i+1; j <= s2.length(); j++){
            temp = s2.substr(i, j-i);
            auto it = subStrings.find(temp);
            if(it != subStrings.end()){
                oldMax = longestMatch;
               longestMatch= max(int(temp.length()), longestMatch);
               if(oldMax!=longestMatch) matchString = temp;
            }
        }
    }

    return make_pair(longestMatch, matchString);
}

int dynamicApproach(string &s1, string &s2){
    int m = s1.size(), n = s2.size();
    int result = 0;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1));
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[i - 1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                result = max(dp[i][j], result);
            }
            else dp[i][j] = 0;
        }
    }
    return result;
}

int main(){
    string s = "Main String";
    string t = "Compare String";
    auto naiveResult = naiveApproach(s, t);
    cout << "Maximum common substring length: " << naiveResult.first << endl;
    cout << "Common substring: " << naiveResult.second << endl;
    auto dpResult = dynamicApproach(s, t);
    cout << "Maximum common substring length: " << dpResult << endl;
    return 0;
}
