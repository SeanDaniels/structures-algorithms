#ifndef __EHT_H_
#define __EHT_H_
#include <vector>
#include <iostream>

// container for inserted elements
class Bucket{
    public:
        std::vector<int> values;
};

// contains pointers to different buckets
class Directory{
    public:
        int dirId;
        // each directory points to a single bucket, but multiple directories can point to the same bucket
        // how to mark if this bucket is being pointed to by multiple directories
        // I'm going to add a flag bit to indicate if the directory points to unique bucket
        char uniqueBucket;
        Bucket* targetBucket;
        Directory(int idNumber){
            dirId = idNumber;
        }
};

// contains pointers to different directories
class EHT{
    public:
        int globalDepth;
        int maskValue;
        int overflowCount;
        std::vector<Directory*> directories;
        EHT();
        ~EHT();
        void insertElement(int element);
        int hashFunc(int element);
        void splitBucket(Bucket* thisBucket);
        void expandDirectory();
        void printBucket(Bucket* thisBucket);
        void printTable();
};


#endif // __EHT_H_
