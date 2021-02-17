#include "eht.hpp"
#define DBG

EHT::EHT(){
  overflowCount = 3;
  globalDepth = 2;
  maskValue = 1;
  for (int i = 0; i < globalDepth; i++) {
    // create new directory, init it with value 0 or 1
    Directory *newDirectory = new Directory(i);
    newDirectory->uniqueBucket = 'T';
    // create new bucket
    Bucket *newBucket = new Bucket();
    // add new bucket to new directory
    newDirectory->targetBucket = newBucket;
    // add directory to EHT's directory vector
    directories.push_back(newDirectory);
  }
}

EHT::~EHT(){
  for(int i = 0; i < this->globalDepth; i++){
    if(this->directories[i]->uniqueBucket=='T'){
      delete(this->directories[i]->targetBucket);
    }
    delete(this->directories[i]);
  }
}

int EHT::hashFunc(int element){
  // determine number of lsbs needed
  int key = element&(this->maskValue);
#ifdef DBG
  std::cout << "Hash key: " << key << std::endl;
#endif
  return key;

}

void EHT::expandDirectory() {
#ifdef DBG
  std::cout << "Expanding directory" << std::endl;
#endif
  // double the number of directories
  int currentDepth = globalDepth;
  int newDepth = currentDepth * 2;
  int partner;
  for (int i = currentDepth; i < newDepth; i++) {
    // create new directory
    Directory *newDirectory = new Directory(i);
    newDirectory->uniqueBucket = 'F';
    partner = i & 1;
#ifdef DBG
    std::cout
        << "New directory points to same bucket as existing directory at index "
        << partner << std::endl;
#endif
    // set new directories bucket to point to the same bucket as it's partner
    newDirectory->targetBucket = this->directories[partner]->targetBucket;
    directories.push_back(newDirectory);
  }
  // update mask value
  maskValue = (maskValue<<1)+1;
#ifdef DBG
  std::cout << "New mask value: " << maskValue << std::endl;
#endif
  globalDepth = newDepth;
}

void EHT::splitBucket(Bucket *thisBucket){
#ifdef DBG
  std::cout << "Splitting bucket" << std::endl;
#endif
  std::vector<int> tempHolder = thisBucket->values;
#ifdef DBG
  std::cout << "Content of holder before clear" << std::endl;
  for(auto x : tempHolder){
    std::cout << x << std::endl;
  }
#endif
  thisBucket->values.clear();
  for(auto x : tempHolder){
#ifdef DBG
  std::cout << "Inserting element  " << x  << std::endl;
#endif
    Directory* targetDirectory = this->directories[hashFunc(x)];
    if(targetDirectory->uniqueBucket=='F'){
#ifdef DBG
      std::cout << "Creating new bucket" << std::endl;
#endif
      Bucket *newBucket = new Bucket();
      // add element to new bucket
#ifdef DBG
      std::cout << "Adding element to new bucket" << std::endl;
#endif
      newBucket->values.push_back(x);
      // mark directory as having a unique bucket
      targetDirectory->uniqueBucket = 'T';
      targetDirectory->targetBucket = newBucket;
    }
    else{
      targetDirectory->targetBucket->values.push_back(x);
    }
  }

}

void EHT::insertElement(int element){
  #ifdef DBG
  std::cout << "--INSERT FUNCTION--" << std::endl << "Element: " << element << std::endl;
  #endif
  // determine directory index by hashing element
  int dirIndex = hashFunc(element);
  // access directory
  #ifdef DBG
  std::cout << "Directory index: " << dirIndex << std::endl;
  #endif
  Directory* targetDirectory = this->directories[dirIndex];
  // If this is the first time inserting an element in this directory
  // asccess directories bucket
  Bucket* targetBucket = targetDirectory->targetBucket;
  // access values in bucket
  targetBucket->values.push_back(element);
#ifdef DBG
    std::cout << "Number of elements in this bucket: " << targetBucket->values.size() << std::endl;
#endif
  if(targetBucket->values.size()>this->overflowCount){
#ifdef DBG
    std::cout << "Bucket overflow " << std::endl;
#endif
    expandDirectory();
    splitBucket(targetBucket);
#ifdef DBG
    std::cout << "Table after update: " << std::endl;
    printTable();
#endif
  }
}

void EHT::printBucket(Bucket *thisBucket){
  for(auto x : thisBucket->values){
    std::cout << x << ", ";
  }
  std::cout << std::endl;
}

void EHT::printTable(){
  // directories contains pointers
  for(auto x : this->directories){
    std::cout << "Directory " << x->dirId << ": ";
    if(x->uniqueBucket=='T'){
      printBucket(x->targetBucket);
    }
    else{
      std::cout << std::endl;
    }
  }

}
