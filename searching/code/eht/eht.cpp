#include "eht.hpp"
#define DBG
EHT::EHT(){
  overflowCount = 3;
  globalDepth = 2;
  maskValue = 1;
  for (int i = 0; i < globalDepth; i++) {
    // create new directory, init it with value 0 or 1
    Directory *newDirectory = new Directory(i);
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
    delete(this->directories[i]->targetBucket);
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
    partner = i & 1;
#ifdef DBG
    std::cout
        << "New directory points to same bucket as existing directory at index "
        << partner << std::endl;
#endif
    newDirectory->targetBucket = this->directories[partner]->targetBucket;
  }
  maskValue *= 2;
#ifdef DBG
  std::cout << "New mask value: " << maskValue << std::endl;
#endif
}

void EHT::insertElement(int element){
  int dirIndex = hashFunc(element);
  Directory* targetDirectory = this->directories[dirIndex];
  Bucket* targetBucket = targetDirectory->targetBucket;
  std::vector<int> bucketVector = targetBucket->values;
  size_t elementCount = bucketVector.size();
#ifdef DBG
    std::cout << "Number of elements in this bucket: " << elementCount << std::endl;
#endif
  if(bucketVector.size()>this->overflowCount){
#ifdef DBG
    std::cout << "Bucket overflow " << std::endl;
#endif
  }
  targetDirectory->targetBucket->values.push_back(element);
}
