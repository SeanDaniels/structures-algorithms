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
        Bucket* targetBucket;
        Directory(int idNumber){
            dirId = idNumber;
        }
};

// contains pointers to different directories
class EHT{
    public:
        int numberOfDirs;
        int maskValue;
        int overflowCount;
        std::vector<Directory*> directories;
        EHT();
        ~EHT();
        void insertElement(int element);
        int hashFunc(int element);
};


#endif // __EHT_H_
