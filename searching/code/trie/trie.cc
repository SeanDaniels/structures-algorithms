#include "trie.h"
#include <cstddef>
#include <vector>
#define DBG


void Trie::insert(std::string thisString){
    TrieNode* curr = this->root;
    TrieNode* tmp;
    int idx;
    for(int i = 0; i < thisString.size(); i++){
        idx = thisString[i] - 48;
        if (curr->children[idx] == NULL) {
#ifdef DBG
          std::cout << "Inserting character " << thisString[i] << " at index "
                    << idx << std::endl;
#endif
          tmp = new TrieNode(thisString[i]);
          curr->children[idx] = tmp;
        }
        curr = curr->children[idx];
    }
    // need to change
    curr->isLeaf = true;
}

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

bool Trie::emptyNode(TrieNode *thisNode){
    for(int i = 0; i < NODE_COUNT; i++){
        if(thisNode->children[i]!=NULL){
           return false;
        }
    }
    return true;
}

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

TrieNode* Trie::printTree(TrieNode* currentNode){
    TrieNode* tmp;
    std::cout << currentNode->data << "-> ";
    for(int i = 0; i < NODE_COUNT; i++){
        if(currentNode->children[i]!=NULL){
            tmp = printTree(currentNode->children[i]);
        }
    }
    return NULL;

}
// TrieNode* Trie::getLeaf(TrieNode *thisNode){
//     std::vector<TrieNode*> currentVector = thisNode->vectorOfNodePointers;
//     if(currentVector.size()>1){
//         std::cout << "Branch found" << std::endl;
//     }
//     TrieNode* tempNode;
//     for(size_t i = 0; i < currentVector.size(); i++){
//        tempNode = currentVector[i];
//        std::cout << tempNode->data;
//        if(tempNode->isLeaf){
//            std::cout << "|" << std::endl;
//            return tempNode;
//        }
//        else{
//            std::cout << "->";
//            return getLeaf(tempNode);
//        }
//     }
//     return tempNode;
// }
// void Trie::printTree(){
//     std::vector<TrieNode*> rootVector = this->root->vectorOfNodePointers;
//     TrieNode *tempA, *tempB;
//     for(int i = 0; i < rootVector.size(); i++){
//         tempA = rootVector[i];
//         std::cout << tempA->data << "->";
//         tempB = getLeaf(tempA);
//     }
// }
// void Trie::insertTrie(std::string thisString){
//     TrieNode* temp = this->root;
//     bool nodeNeeded = true;
//     std::vector<TrieNode*> tempVector = temp->vectorOfNodePointers;
//     for(int i = 0; i < thisString.size(); i++){
//         // check entries in current pointer vector
// #ifdef DBG
//           std::cout << "Checking node for char " << thisString[i] << std::endl;
// #endif
//         for(size_t ii = 0; ii < tempVector.size(); ii++){
//             if(tempVector[ii]->data == thisString[i]){
// #ifdef DBG
//           std::cout << "Node not needed for char " << thisString[i] << std::endl;
// #endif
//                 temp = tempVector[ii];
//                 nodeNeeded = false;
//                 break;
//             }
//         }
//         // add node if necessary
//         if (nodeNeeded) {
// #ifdef DBG
//           std::cout << "Adding node for char " << thisString[i] << std::endl;
// #endif
//           TrieNode *newNode = new TrieNode(thisString[i]);
//           temp->vectorOfNodePointers.push_back(newNode);
//           temp = temp->vectorOfNodePointers.back();
//         } else {
// #ifdef DBG
//           std::cout << "Node not needed, moving on to next character"
//                     << std::endl;
// #endif
//             tempVector = temp->vectorOfNodePointers;
//         }
//         nodeNeeded = true;
//     }
//     temp->isLeaf = true;
// }

// void Trie::insertTrieChar(char thisChar){
//     // create new trie node with character value
//     TrieNode* temp = this->root;
//     for(int i = 0; i < temp->vectorOfNodePointers.size(); i++){
//         if(temp->vectorOfNodePointers[i]->data==thisChar){
//             std::cout << "Node for this character already exists" << std::endl;
//             return;
//         }
//     }
//     TrieNode* newNode = new TrieNode(thisChar);
//     temp->vectorOfNodePointers.push_back(newNode);
//     return;
// }