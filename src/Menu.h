#ifndef FOOBAR1_MENU_H
#define FOOBAR1_MENU_H
#include <set>
#include <vector>



class Menu {
private:
    int arraySize;
    std::set<int> setKeys;
public:
    Menu();
    void getInput();
    int getArraySize();
    void checkValid();
    std::vector<int> getKeysvect();
};


#endif //FOOBAR1_MENU_H
