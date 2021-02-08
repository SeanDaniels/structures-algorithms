A trie, also refereed to as a *digital tree* or *prefix tree*, is a search tree used for located specific keys from within a set. Keys are usually strings, and links between nodes are defined/referenced by single characters.

Nodes in a trie do not store a key value. Trie node's are defined by their position with the structure.

Trie node's have two primary components:
- Children
- A leaf node marker
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
