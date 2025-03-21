#include "HashFunctions.h"

HashFunctions::~HashFunctions(){}

// Applies the standard C++ hash function to a URL and returns the hashed value
size_t HashFunctions::hashing(std::string url) {
    std::hash<std::string> hasher;
    size_t hashResult = hasher(url);
    return hashResult;
}