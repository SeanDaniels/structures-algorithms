#ifndef __EHT_H_
#define __EHT_H_
#include <vector>

// container for inserted elements
class Bucket{
    public:
        std::vector<int> values;
        Bucket();
        ~Bucket();
};

// contains pointers to different buckets
class Directory{
    public:
        int dirId;
        std::vector<Bucket*> buckets;
        Directory(int idNumber){
            dirId = idNumber;
        }
};

// contains pointers to different directories
class EHT{
    public:
        int numberOfDirs;
        std::vector<Directory*> directories;
        EHT();
};


#endif // __EHT_H_
