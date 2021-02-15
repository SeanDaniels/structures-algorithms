---
title: "Tries"
permalink: /topics/tries/
layout: single
toc: true
---

![Example Trie](/structures-algorithms/assets/images/trie.jpg)
<br/><br/>
A trie, also refered to as a digital tree or prefix tree, is a search tree used for locating specific keys from within a set. Keys are usually strings, and links between nodes are defined/referenced by single characters.

Nodes in a trie do not store a key value. Trie node's are defined by their position with the structure.

The first structure I covered was a binary search tree. In that structure, a node contained two pointers. My understanding of a trie is that it can be built as an n-ary tree, meaning that each node can point to n child nodes. 

Typical trie node's have two primary components:
- Some structure containing pointers to the node's children
- A marker designating node as leaf

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

# Initial Thoughts

The idea of storing a vector or array of pointers seems like a bad one. The most common implementation I've found used a pointer for each letter of the alphabet, for each node. A character pointer is four bytes (I think), so each node requires 4*26 bytes of memory. That seems like a lot. Ten nodes would require a kilobyte. 

That seems like a lot of over head for a data structure. 

I also think that as nodes are added to the trie, the number of child nodes decreases. For example, it's reasonable to think that the root node points to the most other nodes, but a node at the lowest level of the trie points to no other nodes. I wonder if there is a way to use vectors or some other dynamic structure to hold the pointers, and save some space overhead.

I am going to pause here and look that up

Here's what I got: 
running the snippet
```c++
vector<char> tmp;
cout << sizeof(tmp) << endl;
```
returns 24.

After running some tests, I realized I was confused about the way sizing and memory allocation works. 

I investigated the following structure:

```c++
struct ObjPointObj{
    char eos;
    ObjPointObj *collection;
};

int main(){
    std::cout << sizeof(ObjPointObj) << std::endl;
}

```

The size of 'ObjPointObj' is 16 bytes. A single pointer (on my system) is 8 bytes, and a char variable is 1 byte. It turns out that the compiler I am using allocates space with respect to byte alignment.


# An Example Use Case

What immediately comes to my mind when learning about tries is a dictionary. When I think about an entry in the dictionary, I think about it's position relative to the entirety of the dictionary. I think that's why most examples use an example with strings as the entry, and characters as the positional references. The prefixing that takes place in a dictionary is intuitive to me, so I am going to use that as a template. 

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

Continuing with the example above, I'll build a trie that processes strings. The characters of the string will be from the english alphabet, meaning each node can potentially point to 26 other nodes.
## Class
I'll be doing this a class object, so my trie node is defined as:
```c++
class TrieNode {
  public:
  // actually containing data, for example purposes
    char data;
    // designator for end of a string
    bool isLeaf;
    // container for node's pointers
    TrieNode* children[NODECOUNT];
    // initializing the pointers
    TrieNode(char nodeData){
        this->data = nodeData;
        this->isLeaf = false;
        for(int i = 0; i < NODECOUNT; i++){
          this->children[i] = NULL;
        }
    }
};
```

## Insertion
When a string is added to the trie, the characters of the string are used to traverse the content of the trie.

The root node pointer structure is checked for the first letter of the string. If present, the function moves to next letter of the string, and points to the node indicated by the root node's pointer. This processed is looped for each letter of the string.

```c++
void Trie::insert(std::string thisString){
    // start at root
    TrieNode* curr = this->root;
    // index for checking current node's pointer array
    int idx;
    for(int i = 0; i < thisString.size(); i++){
    // set index to integer form of character
        idx = thisString[i] - 48;
        // if node does not exist, creat new node, move to new node
        if(!curr->children[idx]){
            curr->children[idx] = new TrieNode(thisString[i]);
            curr = curr->children[idx];
        }
    }
    // node associated with last letter of string marked as a leaf node
    curr->isLeaf = true;
}
```

## Searching

Searching for a given string in the structure is similar:

```c++
bool Trie::searchTrie(std::string thisString){
    TrieNode* curr = this->root;
    int idx;
    for(int i = 0; i < thisString.size(); i++){
        idx = thisString[i] - 48;
        if(!curr->children[idx])
            return false;
        else curr = curr->children[idx];
    }
    return true;
}
```
Starting with the root node and the first character of the string, nodes are checked for the string contents. If at any point in the search, the current node doesn't contain a pointer to the next letter, the search returns as false.

It the trie contained 'arc' and was searched for 'ark':
root -> 'a' (exists) ->  'r' (exists) -> 'k' (doesn't exist) fail return

## Deletion

Deletion, which is handled recursively, can be a little tricky for tries. Here's the process:
- Start at root, first character of string
- Check if depth is equal to length of string
- If depth is equal to string, remove node, move back up through trie
- If not move to next character in string

The depth parameter can only be incremented if the character is found in child pointer arrays. 

Here is the code:
```c++
TrieNode* Trie::remove(TrieNode *currentNode, std::string thisString, int currentDepth){
    if(currentNode==NULL)return NULL;

    // if position in tree matches length of string
    if(currentDepth==thisString.size()){
        if(currentNode->isLeaf){
            currentNode->isLeaf = false;
        }
        if(emptyNode(currentNode)){
            delete(currentNode);
            currentNode = NULL;
        }
    return currentNode;
    }

    int idx = thisString[currentDepth] - 48;
    currentNode->children[idx] = remove(currentNode->children[idx], thisString, currentDepth++);
    if(emptyNode(currentNode)&&currentNode->isLeaf==false){
        delete(currentNode);
        currentNode = NULL;
    }
    return currentNode;
}
```

# Other Thoughts
Like I mentioned above, most example implementations that I have found use a fixed sized array for holding a node's pointers, the ones that point to the node's children. I don't like that approach, so I have decided to use a vector. Vectors are pretty crazy, and I wouldn't begin to try and teach someone else the intricaces of them. What I will say is that they are extendible, which means that I don't have to use a fixed size when creating my trie. 

The downside here is trying to figure the implementation of a trie with vectors. With a fix sized array, all pointers are added to all node pointer arrays at the same position. For example, if a trie only contained contained one entry, the word 'ark', and the trie processed strings, meaning that when a string was added to the trie, traversing the nodes of the trie could produce the string. 
