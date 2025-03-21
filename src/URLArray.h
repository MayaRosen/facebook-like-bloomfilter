#ifndef FOOBAR1_URLARRAY_H
#define FOOBAR1_URLARRAY_H


#include <string>

class URLArray {
public:
    virtual bool execute(const std::string& url) = 0;
    virtual ~URLArray() = default;
};


#endif //FOOBAR1_URLARRAY_H
