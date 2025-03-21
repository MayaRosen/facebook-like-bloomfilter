#ifndef FOOBAR1_URLVECTOR_H
#define FOOBAR1_URLVECTOR_H


#include <vector>
#include <string>

class URLVector {
private:
    std::vector<std::string> urlVect;
public:
    URLVector();
    void addURL(const std::string& url);
    bool searchURL(const std::string& url);
};


#endif //FOOBAR1_URLVECTOR_H
