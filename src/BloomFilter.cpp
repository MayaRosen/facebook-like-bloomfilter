#include <iostream>
#include "URLArray.h"
#include "URLVector.h"
#include <sstream>
#include "BloomFilter.h"
using namespace std;


BloomFilter::BloomFilter(map<std::string, URLArray *> commands): commands(commands) {}

// Executes the appropriate command based on the user's option.
int BloomFilter::run(string option, string url){
    // Validate input: only "1" (add URL) and "2" (search URL) are allowed.
    if (option != "1" && option != "2") {
        return -1;
    }
    
    // Execute the corresponding operation from the commands map.
    return commands[option]->execute(url);
};