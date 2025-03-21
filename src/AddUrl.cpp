#include "AddUrl.h"
#include "HashFunctions.h"
#include "Hash1.h"
#include "Hash2.h"

AddUrl::AddUrl(int arraySize, bool* arr, int key1, int key2, URLVector* urlVector):
        arraySize(arraySize) , arr(arr),key1(key1), key2(key2), urlVector(urlVector) {}

// Adds a URL to the Bloom Filter and marks the corresponding bits in the bit array.
bool AddUrl::execute(const std::string &url) {
    HashFunctions *hash = nullptr;

    // Store the URL in the URLVector.
    urlVector->addURL(url);

    // Apply the selected hash functions and update the bit array.
    if (key1 == 1 || key2 == 1) {
        hash = new Hash1(arraySize, url);
        arr[hash->doHash()] = true;
    }
    if (key1 == 2 || key2 == 2){
        hash = new Hash2(arraySize, url);
        arr[hash->doHash()] = true;
    }

    // Clean up dynamically allocated memory.
    delete hash;
    return false;
}