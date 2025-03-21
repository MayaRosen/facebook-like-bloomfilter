#include "Menu.h"
using namespace std;
#include <iostream>
#include <limits>

Menu::Menu() {
    arraySize = 0;
}

// Gets user input: first the array size, then one or two hash function keys (1 or 2).
void Menu::getInput() {
    // Get array size and validate the input
    cin >> arraySize;
    while (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> arraySize;
    }

    // If no hash function was entered, restart input collection
    if (cin.peek() == '\n'){
        getInput();
        return;
    }

    // Get hash function keys (expecting 1 or 2)
    while (cin.peek() != '\n'){
        int key;
        cin >> key;

        // If input is invalid, reset and restart
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setKeys.clear();
            getInput();
            return;
        }

        // Add the key and validate
        setKeys.insert(key);
        checkValid();
    }
}

// Validates that all keys in the set are either 1 or 2
void Menu::checkValid() {
    auto it = setKeys.begin();
    for (int i = 0; i < setKeys.size(); i++) {
        if (*it != 1 && *it != 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setKeys.clear();
            getInput();
            return;
        }
        it++;
    }
}

// Returns the Bloom Filter array size
int Menu::getArraySize() {
    return arraySize;
}

// Converts the set of hash keys to a vector and pads it to ensure it contains 2 values
std::vector<int> Menu::getKeysvect() {
    //convert set to vector of keys and return vector
    vector<int> keysVect;
    auto it = setKeys.begin();
    for (int i = 0; i < setKeys.size(); i++) {
        keysVect.push_back(*it);
        it++;
    }

    // Pad with 0 if less than 2 hash functions were selected
    while (keysVect.size() < 2){
      keysVect.push_back(0);
    }
    
    return keysVect;
}
