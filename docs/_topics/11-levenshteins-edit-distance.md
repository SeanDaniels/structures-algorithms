---
title: "Levenshtein's Edit Distance"
permalink: /topics/levenshteins-edit-distance/
layout: single
toc: true
---


Lenshtein's Edit Distance is an algorithm for determining the difference between two strings. The algorithm determines the minimum number of changes necessary to transform one string into another string. The changes available to be made are:

- Insert a character
- Delete a character
- Replace a character

## Example

pet
get

to transform pet into get, the minimum number of transformations is one. P needs to be tranformed into g. 

Peter
Getting

to transform Peter into Getting, the following actions need to be taking on Peter:

- Replace P with G
- Replace second e with t
- Replace r with i
- Insert n
- Insert g

## Bounds

The minimum number of changes is at least the difference between the size of the two strings. The maximum number of changes is at most the size of the larger string.

## Why is this a dynamic programming candidate?

It is possible to build the solution for this problem by combining the solution of subsets of problems within the overall problem.

The two strings can be visualized with the following layout:

|   | S | i | t | t | i | n | g |
|---|---|---|---|---|---|---|---|
| K |   |   |   |   |   |   |   |
| i |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |
| e |   |   |   |   |   |   |   |
| n |   |   |   |   |   |   |   |

The characters of string 'a' define the columns of a table and the characters of string 'b' define the rows of the same table. Starting with the first row, the character of string 'b' associated with this row ('K') is compared with the characters associated with column position of the table. From the left to right, the comparisons are 'K' and 'S', 'Si', 'Sit', 'Sitt', 'Sitti', 'Sittin', 'Sitting'.


These comparisons are all subsets of the larger problem. The character 'K' can be transformed to 'S' with one replacement operation, so the table value is 1. The character 'K' can be transformed to 'Si' with two operations, a replacement and an insertion. For the first row of the table, the values are built by iterating through the columns and incrementing the number of changes needed. The logic behind this is that after the first comparison, which is 'K' compared with 'S', the character 'K' is compared with a string of a growing size. Regardless of the character associated with the column position, the minimum number of edits will be equal to the difference between the lengths of the character 'K' (1) and the growing strings ('S', 'Si', 'Sit', ...) 

## Solving dynamically

The first row and first column of the table need to be initialized as a strarting point for dynamic approach. 

The code for creating and initializing the table is as follows:
```c++
// create table (vector of vectors)
vector<vector<int>> dp(a.size(), vector<int>(b.size()));
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
```

Here is the table after initializing the first row:


|   | S | i | t | t | i | n | g |
|---|---|---|---|---|---|---|---|
| K | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| i |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |
| e |   |   |   |   |   |   |   |
| n |   |   |   |   |   |   |   |

The same logic is used to initialize the first column of the table. Instead of comparing 'K' with growing strings, 'S', the first character of string 'b' is used. 'S' is compared with 'K', 'Ki', 'Kit', ...

Here is the table after the first column is initialized:

|   | S | i | t | t | i | n | g |
|---|---|---|---|---|---|---|---|
| K | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| i | 2 |   |   |   |   |   |   |
| t | 3 |   |   |   |   |   |   |
| t | 4 |   |   |   |   |   |   |
| e | 5 |   |   |   |   |   |   |
| n | 6 |   |   |   |   |   |   |


After the table is initialized, the remaining cells are populated. The first entry populated will be at column = 1, row = 1. The characters being compared are string a[1] and string b[1], which correspond to characters 'i' and 'i'. This comparison results in a match. Because this character is a match, the number of operations necessary to transform 'Ki' into 'Si' is equivalent to the number of operations to transform 'K' to 'S'. This value is stored in the table at the previous row position a the previous column position. The remainder of this row is populated by comparing the string 'Ki' with the growing strings 'Sit', 'Sitt', 'Sittin', and 'Sitting'.

When 'Ki' is compared with 'Sit', an non match is found. Just like the first row, the value added to the table is the value at the previous position in the table incremented by 1. When the size of the growing string is greater than the fixed string, the value added to the table is the previous table entry incremented by one. Deviating from the original example, imagine if the two strings were simply 'Hi' and 'Pies'. When comparing 'Hi' to 'Pie' and 'Pies', it doesn't really matter if the last characters checked match. To convert some string with two letters to some string three letters, the last operation will be an insertion, so the number of operations will increase by one. As the gap between the size of string being converted and string template grows, the number of insertions increases at a constant rate. 

Here is the code to populate the rest of the table:

```c++
for(int i = 1; i < a.size(); i++){
    for(int j = 1; j < b.size(); j++){
    // if length of growing string is greater than the length of the fixed string
        if(j>i)dp[i][j] = dp[i][j-1]+1;
        // if the character match
        else if(a[i]==b[j]) dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
        // if the characters don't match
        else{
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
    }
}
```


here is the table after the second row is processed:


|   | S | i   | t | t | i | n | g |
|---|---|-----|---|---|---|---|---|
| K | 1 | 2   | 3 | 4 | 5 | 6 | 7 |
| i | 2 | *1* | 2 | 3 | 4 | 5 | 6 |
| t | 3 |     |   |   |   |   |   |
| t | 4 |     |   |   |   |   |   |
| e | 5 |     |   |   |   |   |   |
| n | 6 |     |   |   |   |   |   |

The third row adds a layer of complexity. The first comparison of the third row are the strings 'Kit' and 'Si'. In order to transform 'Kit' to 'Si', Two operations are needed. 'K' needs to be replaced with 'S' and 't' needs to be deleted. In the previous rows, the result of mismatch was incrementing the previous column position by 1. If the same logic was applied here, the table would indicate 4 operations needed to transform 'Kit' into 'Si', which is not correct. The logic desired is an answer the following question: "What is the result of appending a single letter to one of the strings being compared?". The intuitive response to this question is the result of the comparison of strings before the letter was appended plus whatever happens as a result of the new letter.

In this case, the result is not 3 + 1, it's 1+1. 

The next comparison is between the strings 'Sit' and 'Kit'. The characters being compared are string a[2] and string b[2], both of which are 't'. The match means that the value from the table need not be incremented. Which table value should be copied? The value from the previous string comparison of 'Kit' and 'Si', before the 't' was appended to 'Si'.

The next comparison is between 'Kit' and 'Sitt'. The character at string a[2] is being compare to b[3], and both of these characters are 't'. The comparison returns true. Again, transforming 'Kit' into 'Sitt' requires two transformations. Replacing 'K' with 'S' and removing the last 't' in 'Sitt'. This is the same number of operations necessary to tranform 'Ki' into 'Sit', which has already been updated in the table. 

Here is the table after the third row has been populated:

|   | S | i   | t   | t | i | n | g |
|---|---|-----|-----|---|---|---|---|
| K | 1 | 2   | 3   | 4 | 5 | 6 | 7 |
| i | 2 | *1* | 2   | 3 | 4 | 5 | 6 |
| t | 3 | 2   | *1* | 2 | 3 | 4 | 5 |
| t | 4 |     |     |   |   |   |   |
| e | 5 |     |     |   |   |   |   |
| n | 6 |     |     |   |   |   |   |

The rest of table is updated in the same way. An important question has not been answered. After initialization, which previous value is referenced when determining the value associated with the current comparison?

The short answer is the minimum value contained in table at the following positions: 

- Previous column, previous row
- Same column, previous row
- Previous column, same row

*or* 

min(table[i-1][j], table[i][j-1], table[i-1][j-1])

The current table value will either be a copy of this minimum value, or the minimum value incremented by 1. 

The beauty of this approach is that sub-problems are solved incrementally, and each sub-problems solution has a very simple relationship with the previous sub-problems solution. 

Here is the table populated in it's entirety:


|   | S | i   | t   | t   | i | n   | g |
|---|---|-----|-----|-----|---|-----|---|
| K | 1 | 2   | 3   | 4   | 5 | 6   | 7 |
| i | 2 | *1* | 2   | 3   | 4 | 5   | 6 |
| t | 3 | 2   | *1* | 2   | 3 | 4   | 5 |
| t | 4 | 3   | 2   | *1* | 2 | 3   | 4 |
| e | 5 | 4   | 3   | 2   | 2 | 3   | 4 |
| n | 6 | 5   | 4   | 3   | 3 | *2* | 3 |


The minimum edit distance is located in the last row, at the last column position. This position in the table corresponds to comparing all the characters of the first string to all the characters of the second string.

Here is the full code:

```c++
#include <bits/stdc++.h>
using namespace std;

// just a helper to show table as it's being created/ after it's populated
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
    // row 0 comes from comparing a[0] with b[0] through b[size of b - 1]
    // column 0 comes from comparing b[0] with a[0] through a[size of a - 1]
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
```

