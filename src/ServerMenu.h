#ifndef FOOBAR1_SERVERMENU_H
#define FOOBAR1_SERVERMENU_H
#include "set"
#include <vector>



class ServerMenu {
private:
    int arraySize;
    std::set<int> setKeys;

public:
    ServerMenu(int arraySize, std::set<int> setKeys);
    bool CheckValid();
    int getArraySize();
    std::vector<int> getKeys();
};


#endif //FOOBAR1_SERVERMENU_H
