#include "eht.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    EHT extendibleTable;
    vector<int> insertValues = {16,4,6,22,24,10,31,7,9,20,26};
    for(auto x : insertValues){
        extendibleTable.insertElement(x);
    }
    return 0;
}
