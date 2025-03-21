#ifndef FOOBAR1_HASH1_H
#define FOOBAR1_HASH1_H
#include <iostream>
#include "HashFunctions.h"

class Hash1:public HashFunctions {
private:
    int arraySize;
    std::string url;

public:
    Hash1(int arraySize, std::string url);
    int doHash() override;
};


#endif //FOOBAR1_HASH1_H
