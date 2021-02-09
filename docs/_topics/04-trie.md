---
title: "Tries"
permalink: /topics/tries/
layout: single
toc: true
---

![Example Trie](/structures-algorithms/assets/images/trie.jpg)
<br/><br/>
A trie, also refereed to as a *digital tree* or *prefix tree*, is a search tree used for located specific keys from within a set. Keys are usually strings, and links between nodes are defined/referenced by single characters.

Nodes in a trie do not store a key value. Trie node's are defined by their position with the structure.

The first structure I covered was a binary search tree. In that structure, a node contained two pointers. My understanding of a trie is that it can be built as an n-ary tree, meaning that each node can point to n child nodes. 

Typical trie node's have two primary components:
- Children
- A leaf node marker

A node's children are stored as pointers in an additional data structure. The examples that I have found so far use a fixed sized array, with a lay out looking something like this:

```c++
class TrieNode(){
public:
// only used here to print the data
char data;
// matrix of pointers
TrieNode* children[n];
// bool value to determine if a given node is a leaf node
bool isLeaf;
};
```
# An Example Use Case

What immediately comes to my mind when learning about tries is a dictionary. When I think about an entry in the dictionary, I think about it's position relative to the entirety of the dictionary. I think that's why most examples use an example with strings as the entry, and characters as the positional references. The prefixing that takes place in a dictionary is intuitive to me, so I am going to use that format. 

Let's say I wanted to store a bunch of words in some program, I'm going to use a trie, and the first word I was going to add was 'ark'. Because the trie is empty, I am going to be adding three nodes, a node representing each letter, pointing to the next letter in the word, until the last letter, which I will flag as the end of a word. Here's a quick representation:

root node -> node containing a -> node containing r -> node containing k (flagged as end of word)

To accomplish this:
- A node for each letter is created
- Each node contains a pointer to the next letter in the word

Suppose I add another word, 'arch'. In this case, I will only be adding two nodes, one for c and on for h.

root node -> node containing a -> node containing r -> (new) node containing c -> (new) node containing h (flagged as end of word)

To accomplish this, two things happened:
- Two new nodes were created
- The collection of pointers owned by the node that contains r is updated to now also point to c

If I were to add the word 'bark' to the structure, four nodes would be added. The idea of prefixing is important. For a given word, I only reference existing nodes until a novel character is introduced. If the first character of the string is not present in the pointer list of the root node, I need to start a new branch of the trie.

# Building the Structure

I have been building the example structures with c++ being the programming language. I hope that it's clear that the underlying logic and algorithms for these structures are not linked to any particular language. For the sake of continuity, I am going to again use c++ for the trie structure. 

Like I mentioned above, most example implementations that I have found use a fixed sized array for holding a node's pointers, the ones that point to the node's children. I don't like that approach, so I have decided to use a vector. Vectors are pretty crazy, and I wouldn't begin to try and teach someone else the intricaces of them. What I will say is that they are extendible, which means that I don't have to use a fixed size when creating my trie. 

The downside here is trying to figure the implementation of a trie with vectors. With a fix sized array, all pointers are added to all node pointer arrays at the same position. For example, if a trie only contained contained one entry, the word 'ark', and the trie processed strings, meaning that when a string was added to the trie, traversing the nodes of the trie could produce the string. 
