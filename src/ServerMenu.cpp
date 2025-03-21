#include "ServerMenu.h"
#include <vector>
using namespace std;
ServerMenu::ServerMenu(int arraySize, std::set<int> setKeys) : arraySize(arraySize), setKeys(setKeys){}

// Validates the input provided by the client:
// - Array size must be positive
// - Hash function keys must be 1 or 2
bool ServerMenu::CheckValid() {
    if (arraySize <= 0) {
        return false;
    }

    if (setKeys.empty()) {
        return false;
    }

    // Check that all keys are either 1 or 2
    for (int key : setKeys) {
        if (key != 1 && key != 2) {
            return false;
        }
    }
    return true;
}

int ServerMenu::getArraySize() {
    return arraySize;
}

// Converts the set of selected hash function keys to a vector and pads the vector to ensure it always has 2 values
std::vector<int> ServerMenu::getKeys(){
    vector<int> keysVect;

    // Copy keys from set to vector
    auto it = setKeys.begin();
    for (int i = 0; i < setKeys.size(); i++) {
        keysVect.push_back(*it);
        it++;
    }
    
    // Pad with 0 if fewer than 2 hash functions were selected
    while (keysVect.size() < 2){
        keysVect.push_back(0);
    }
    return keysVect;
}



