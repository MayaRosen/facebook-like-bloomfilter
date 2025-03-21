#ifndef FOOBAR1_SEARCHURL_H
#define FOOBAR1_SEARCHURL_H
#include <string>
#include "URLArray.h"
#include "URLVector.h"
#include "HashFunctions.h"

class SearchUrl:public URLArray {
private:
    bool* arr;
    int key1, key2;
    int arraySize;
    URLVector* urlVector;
public:
    SearchUrl(int arraySize, bool* arr,int key1, int key2, URLVector* urlVector);
    bool execute(const std::string& url);
    };


#endif //FOOBAR1_SEARCHURL_H
