#ifndef FOOBAR1_MENUS_H
#define FOOBAR1_MENUS_H
#include "vector"
using namespace std;

class Menus {
public:
    virtual void getInput() = 0;
    virtual int getArraySize() = 0;
    virtual void checkValid() = 0;
    virtual std::vector<int> getKeysvect() = 0;
    virtual ~Menus() = default;
};

#endif //FOOBAR1_MENUS_H
