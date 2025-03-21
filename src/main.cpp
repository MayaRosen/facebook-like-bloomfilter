#include <map>
#include <string>
#include <iostream>
#include "URLArray.h"
#include "AddUrl.h"
#include "SearchUrl.h"
#include "BloomFilter.h"
#include "Menu.h"
#include "ServerBloom.h"

using namespace std;


int main(){
    // Create and start the server logic
    ServerBloom server = ServerBloom();
    server.server();
    return 1;
}