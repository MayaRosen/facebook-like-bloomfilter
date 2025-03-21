#include "Hash2.h"
#include <string>
using namespace std;

Hash2::Hash2(int arraySize, std::string url) : arraySize(arraySize), url(url){}
// Computes the hash of the URL, then hashes the result again, and applies modulo operation to fit within the array size.
int Hash2::doHash() {
    size_t firstHash = hashing(url);
    size_t secondHash = hashing(to_string(firstHash));
    return static_cast<int>(secondHash % arraySize);
}
