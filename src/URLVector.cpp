#include "URLVector.h"
#include <algorithm>
URLVector::URLVector() {}

// adds the url to the vector
void URLVector::addURL(const std::string& url) {
    urlVect.push_back(url);
}

//searchs if the url is in the vector
bool URLVector::searchURL(const std::string& url) {
    if (std::find(urlVect.begin(), urlVect.end(), url) != urlVect.end()){
        return true;
    }
    return false;
}
