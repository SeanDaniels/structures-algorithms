#include <iostream>
#include "trie.h"

using namespace std;

int main(int argc, char *argv[]) {
    Trie myTree;
    myTree.insertTrie("Ted");
    myTree.printTree();
    myTree.insertTrie("Hi");
    myTree.printTree();
    myTree.insertTrie("High");
    myTree.printTree();
    cout << "Number of entries in root vector: " << myTree.root->vectorOfNodePointers.size() << endl;
    return 0;
}
