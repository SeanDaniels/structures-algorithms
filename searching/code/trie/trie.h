#ifndef __TRIE_H_
#define __TRIE_H_
#include <vector>
#include <string>
#include <iostream>

class TrieNode {
  public:
    char data;
    int numberOfChildren;
    bool isLeaf;
    std::vector<TrieNode*> vectorOfNodePointers;
    TrieNode(char nodeData){
        this->data = nodeData;
        this->isLeaf = false;
    }
};

class Trie {
public:
  TrieNode* root;
  Trie(){
      root = new TrieNode('\0');
  }
  // Helper Functions
  TrieNode* findChar(char thisChar);
  TrieNode* getLeaf(TrieNode* thisNode);
  void printTree();
  bool searchTrie(std::string thisString);
  void insertTrieChar(char thisChar);
  void insertTrie(std::string thisString);
};

#endif // __TRIE_H_
