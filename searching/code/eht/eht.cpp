#include "eht.hpp"

EHT::EHT(){
  numberOfDirs = 2;
  for (int i = 0; i < 2; i++) {
    // create new directory, init it with value 0 or 1
    Directory *newDirectory = new Directory(i);
    // create new bucket
    Bucket *newBucket = new Bucket();
    // add new bucket to new directory
    newDirectory->buckets.push_back(newBucket);
    // add directory to EHT's directory vector
    directories.push_back(newDirectory);
  }
}
