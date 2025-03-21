#include "Hash1.h"
Hash1::Hash1(int arraySize, std::string url) : arraySize(arraySize), url(url){}

// Computes the hash of the URL and applies modulo operation to fit within the array size
int Hash1::doHash() {
    return static_cast<int>(hashing(url) % arraySize);
}
