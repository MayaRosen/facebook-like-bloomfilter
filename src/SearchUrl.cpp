#include "SearchUrl.h"
#include "HashFunctions.h"
#include "Hash1.h"
#include "Hash2.h"
#include "URLVector.h"
#include <iostream>

using namespace std;

SearchUrl::SearchUrl(int arraySize, bool* arr, int key1, int key2, URLVector* urlVector):
arraySize(arraySize) , arr(arr), key1(key1), key2(key2), urlVector(urlVector) {}

// Checks if a URL might exist in the Bloom Filter and verifies it with the stored URL list.
bool SearchUrl::execute(const std::string &url) {
    HashFunctions *hash = nullptr;
    
    // Use Hash1 if selected
    if (key1 == 1 || key2 == 1) {
        hash = new Hash1(arraySize, url);
        if (!arr[hash->doHash()]){
            return false;
        }
    // Use Hash2 if selected
    } if (key1 == 2 || key2 == 2) {
        hash = new Hash2(arraySize, url);
        if (!arr[hash->doHash()]){
            return false;
        }
    }
    //if it wasn't found return false
    if (key1 != 1 && key1 != 2 && key2 != 1 && key2 != 2){
        return false;
    }

    delete hash;
    // Check if the URL is actually stored (avoiding false positives)
    if (urlVector->searchURL(url) == 1) {
        return true;
    } else{
        return false;
    }
}