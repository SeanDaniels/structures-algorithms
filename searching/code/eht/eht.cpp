#include "eht.hpp"
#define DBG
EHT::EHT(){
  overflowCount = 3;
  numberOfDirs = 2;
  maskValue = 1;
  for (int i = 0; i < 2; i++) {
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
  for(int i = 0; i < this->numberOfDirs; i++){
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
