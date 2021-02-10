#include <iostream>
#include "trie.h"

using namespace std;

int main(int argc, char *argv[]) {
    Trie myTree;
    TrieNode* tmp;
    string foo = "foo";
    myTree.insert(foo);
    if(myTree.searchTrie(foo)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    myTree.insert("Bar");
    myTree.insert("Baz");
    return 0;
}
