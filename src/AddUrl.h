#ifndef FOOBAR1_ADDURL_H
#define FOOBAR1_ADDURL_H
#include <string>
#include "URLArray.h"
#include "URLVector.h"

class AddUrl: public URLArray{
private:
    bool* arr;
    int key1, key2;
    int arraySize;
    URLVector* urlVector;
public:
    AddUrl(int arraySize, bool* arr, int key1, int key2, URLVector* urlVector);
    bool execute(const std::string& url);
};


#endif //FOOBAR1_ADDURL_H
