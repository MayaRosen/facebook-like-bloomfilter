#ifndef FOOBAR1_HASH2_H
#define FOOBAR1_HASH2_H


#include <iostream>
#include "HashFunctions.h"

class Hash2:public HashFunctions {
private:
    int arraySize;
    std::string url;

public:
    Hash2(int arraySize, std::string url);
    int doHash();
};


#endif //FOOBAR1_HASH2_H
