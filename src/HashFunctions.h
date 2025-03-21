#ifndef FOOBAR1_HASHFUNCTIONS_H
#define FOOBAR1_HASHFUNCTIONS_H
#include <string>

class HashFunctions {

public:
    virtual ~HashFunctions();
    size_t hashing(std::string url);
    virtual int doHash() = 0;
};


#endif //FOOBAR1_HASHFUNCTIONS_H
