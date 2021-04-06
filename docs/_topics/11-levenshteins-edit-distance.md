---
title: "Levenshtein's Edit Distance"
permalink: /topics/levenshteins-edit-distance/
layout: single
toc: true
---
# What is it
Difference between two strings. The minimum number of changes necessary to transform one string into another string. The changes available to be made are:

- Insert a character
- Delete a character
- Replace a character

## Examples

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

The characters of string 'a' define the columns of a table and the characters of string 'b' define the rows of the same table. Starting with the first row, the character of string 'b' associated with this row ('K') is compared with the characters associated with column position of the table. From the left to right, the comparisons are:

- Does 'S' = 'K'? How many changes necessary to transform 'K' into 'S'?
- Does 'Si' = 'K'? How many changes necessary to transform 'K' into 'Si'?

These comparisons are all subsets of the larger problem. The character 'K' can be transformed to 'S' with one replacement operation, so the table value is 1. The character 'K' can be transformed to 'Si' with two operations, a replacement and an insertion. For the first row of the table, the values are built by 

