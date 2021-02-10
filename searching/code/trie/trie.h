#ifndef __TRIE_H_
#define __TRIE_H_
#include <vector>
#include <string>
#include <iostream>
#define NODE_COUNT  26

class TrieNode {
  public:
    char data;
    bool isLeaf;
    TrieNode* children[NODE_COUNT];
    TrieNode(char nodeData){
      std::cout << "Creating node to hold character " << nodeData << std::endl;
        this->data = nodeData;
        this->isLeaf = false;
        for(int i = 0; i < NODE_COUNT; i++){
          this->children[i] = NULL;
        }
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
  TrieNode* remove(TrieNode* currentNode, std::string thisString, int currentDepth = 0);
  TrieNode* printTree(TrieNode* currentNode);
  bool searchTrie(std::string thisString);
  bool emptyNode(TrieNode* thisNode);
  void insertTrieChar(char thisChar);
  void insert(std::string thisString);
};

#endif // __TRIE_H_
