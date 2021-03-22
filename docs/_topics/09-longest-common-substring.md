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

The naive approach consists of generating all possible substrings of string one, storing those substrings, generating all possible substrings of string two, and comparing them with all of the stored substrings of string one. If a match is found, the length of the match is compared against the current longest match value. If the new matches length is greater than the current longest match value, the current longest match value is updated to reflect the new longest match value.

Here is an example of this naive solution, using a map structure.
```c++
int main(){
    // string one
    string s = "Main String";
    // string two
    string t = "Compare String";
    // containers for substrings and longest substring
    string temp, commonSubString;
    // counter for max value
    int maxMatchLength = 0, oldMax;
    // map to hold substrings
    map<string,string> mapOfSubstrings;
    // iterator for map, to use in searching map
    map<string,string>::iterator it;
    // window string one, grow window size, storing all unique substrings windowed
    for(size_t i = 0; i < s.length(); i++){
        for(size_t j = i+1; j <= s.length(); j++){
            // store substring
            temp = s.substr(i, j-i);
            // search map for substring
            it = mapOfSubstrings.find(temp);
            // if substring doesn't exist in map, store it in map
            if(it == mapOfSubstrings.end()){
                mapOfSubstrings.insert({temp, temp});
            }
        }
    }
    // window string two, grow window size, search map for substring
    for(size_t i = 0; i < t.length(); i++){
        for(size_t j = i+1; j <= t.length(); j++){
            // store substring
            temp = t.substr(i, j-i);
            // search for substring
            it = mapOfSubstrings.find(temp);
            // if substring does exist
            if(it != mapOfSubstrings.end()){
                oldMax = maxMatchLength;
                // compare substring length with current max, save larger
                maxMatchLength = max(int(temp.length()), maxMatchLength);
                if(oldMax!=maxMatchLength) commonSubString = temp;
            }
        }
    }
    return 0;
}
```
