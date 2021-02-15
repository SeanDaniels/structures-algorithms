#include <iostream>
#include "trie.h"

using namespace std;

int main(int argc, char *argv[]) {
    Trie myTree;
    //TrieNode* tmp;
    string foo = "foo";
    string bar = "bar";
    myTree.insert(foo);
    if(myTree.searchTrie(foo)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    myTree.insert(bar);
    if(myTree.searchTrie(bar)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    myTree.insert("Baz");
    myTree.printTree(myTree.root);

    return 0;
}
