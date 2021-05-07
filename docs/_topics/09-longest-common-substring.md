---
title: "Longest Common Substring"
permalink: /topics/longest-common-substring/
layout: single
toc: true
---
# Naive Approach

string one = "Pet"
string two = "Get"

possible substrings of Pet: P, Pe, Pet, e, et, t
possible substrings of Get: G, Ge, Get, e, et, t

A naive approach consists of generating all possible substrings of string one, storing those substrings, generating all possible substrings of string two, and comparing them with all of the stored substrings of string one. If a match is found, the length of the match is compared against the current longest match value. If the new match's length is greater than the current longest match value, the current longest match value is updated to reflect the new longest match value.

Here is an example of this naive solution, using a map structure.

```c++
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

int main(){
    string s = "Main String";
    string t = "Compare String";
    auto naiveResult = naiveApproach(s, t);
    cout << "Maximum common substring length: " << naiveResult.first << endl;
    cout << "Common substring: " << naiveResult.second << endl;
    return 0;
}
```

# Dynamic Approach

This problem lends itself to a dynamic approach. The ultimate solution consists of a number of sub-solutions linked together. 

The dynamic approach consists of building a table, and populating entries in the table based on the number of matches found.

Again, consider the following two strings:

String A: Pet
String B: Get

The table is built with one string determining the number of rows, and one string determining the number of columns. The first row and the first column of the table are initialized to 0. The table is shown below:

|   | P | E | T |
| G | 0 | 0 | 0 |
| E | 0 | 1 | 0 |
| T | 0 | 0 | 2 |

For each column of each following row, the characters of the two strings are compared. If the two characters do not match, a 0 entry is added to the table. If the two characters match, the value of the previous match is incremented by 1. This works due to the indexing of the table. The value returned for two character's matching depends on the number of consecutive previous character matches. 

Here is the code for solving with the dynamic approach:

```c++
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
    auto dpResult = dynamicApproach(s, t);
    cout << "Maximum common substring length: " << dpResult << endl;
    return 0;
}
```


    

## Code
[Link to code](https://github.com/SeanDaniels/structures-algorithms/tree/gh-pages/dynamic-programming/code/longest-common-subsequence){: .btn}
