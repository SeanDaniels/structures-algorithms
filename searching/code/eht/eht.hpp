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
        void splitBucket();
        void expandDirectory();
};


#endif // __EHT_H_
