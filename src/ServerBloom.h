#ifndef FOOBAR1_SERVERBLOOM_H
#define FOOBAR1_SERVERBLOOM_H


#include "URLVector.h"
#include "BloomFilter.h"
#include "SearchUrl.h"
#include <optional>

class ServerBloom {
private:
    bool initialized = false;
    BloomFilter* bloomFilter;
public:
    ServerBloom();
    void server();
    void handleClient(int client_sock);
    void handleInitialized(int client_sock);
    };


#endif //FOOBAR1_SERVERBLOOM_H
