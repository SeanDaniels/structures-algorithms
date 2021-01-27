#include <iostream>
#include <random>
#include "bst.h"

using namespace std;

int main(int argc, char *argv[]) {

  std::default_random_engine generator;
  std::uniform_int_distribution<int> dist(0, 1000);
  BST *testTree = new BST();
  for(int i = 0; i < 10; i++){
      testTree->insert(dist(generator));
  }
  delete testTree;
  return 0;
}
