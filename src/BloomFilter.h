#ifndef FOOBAR1_BLOOMFILTER_H
#define FOOBAR1_BLOOMFILTER_H
#include <map>
#include <string>
#include <iostream>
#include "URLArray.h"
using namespace std;
class BloomFilter{
private:
    map<string, URLArray*> commands;
public:
    BloomFilter(map<string, URLArray*> commands);
    int run(string option, string url);
};
#endif //FOOBAR1_BLOOMFILTER_H
