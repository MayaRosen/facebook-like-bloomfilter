#include "ServerBloom.h"
#include "SearchUrl.h"
#include "ServerMenu.h"
#include "AddUrl.h"
#include <sstream>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include <set>

using namespace std;

// This function handles communication with a single client.
// It expects the first message to contain Bloom Filter configuration (array size + hash keys).
// Subsequent messages are commands: either to add a URL or to check if one exists.
void ServerBloom::handleClient(int client_sock) {
    const int buffer_size = 4096;
    char buffer[buffer_size];

    while (true) {
        // Receive data from the client
        int read_bytes = recv(client_sock, buffer, buffer_size, 0);

        if (read_bytes == 0) {
            // Client closed the connection
            cout << "Client closed the connection" << endl;
            close(client_sock);
            return;
        } else if (read_bytes < 0) {
            // Error receiving data
            perror("error receiving from client");
            close(client_sock);
            return;
        }

        buffer[read_bytes] = '\0';
        cout << "Received: " << buffer << endl;

        if (!initialized) {
            // First message from client: used for initialization
            istringstream iss(buffer);
            string line;
            int arraySize;
            set<int> setKeys;

            // Read the first line → array size
            if (getline(iss, line)) {
                if (!line.empty()) {
                    arraySize = stoi(line);
                }
            }

            // Read remaining lines → hash function keys (1 or 2)
            while (getline(iss, line)) {
                if (!line.empty()) {
                    int key = stoi(line);
                    setKeys.insert(key);
                }
            }

            // Create a ServerMenu to validate input
            ServerMenu menu(arraySize, setKeys);
            map<string, URLArray*> commands;

            // If valid input, initialize Bloom Filter components
            if (menu.CheckValid()) {
                // Initialize bit array with false
                bool* arr = new bool[menu.getArraySize()];
                for (int i = 0; i < menu.getArraySize(); ++i) {
                    arr[i] = false;
                }
                
                 // Stores actual URLs for verification
                URLVector* urlVect = new URLVector();


                // Set up Add URL operation
                URLArray* addUrl = new AddUrl(menu.getArraySize(), arr, menu.getKeys()[0], menu.getKeys()[1], urlVect);
                commands["1"] = addUrl;

                // Set up Search URL operation
                URLArray* searchUrl = new SearchUrl(menu.getArraySize(), arr, menu.getKeys()[0], menu.getKeys()[1], urlVect);
                commands["2"] = searchUrl;

                // Create BloomFilter object with command map
                bloomFilter = new BloomFilter(commands);
                initialized = true;
            } else {
                cout << "Invalid input" << endl;
            }

            // Notify client of initialization status
            string response = initialized ? "Initialization successful" : "Initialization failed";
            send(client_sock, response.c_str(), response.length(), 0);
        } else {
            // After initialization: expect operation commands
            istringstream iss(buffer);
            string option, url;
            bool found = false;

            // Parse one or more commands from the client
            while (getline(iss, option, '\n') && getline(iss, url, '\n')) {
                if (bloomFilter && bloomFilter->run(option, url.c_str())) {
                    found = true;
                    break;
                }
            }

            // Send result back to client
            string response = found ? "true" : "false";
            send(client_sock, response.c_str(), response.length(), 0);
        }
    }
}


ServerBloom::ServerBloom(){
    bloomFilter = nullptr;
}

// Main server function: creates socket, listens for connections, and handles each client in a separate thread
void ServerBloom::server() {
    const int server_port = 5555;
    
    // Create the server socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return;
    }

    // Set up server address structure
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    // Bind socket to port
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        close(sock);
        return;
    }

    // Start listening for client connections (up to 5 in backlog)
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        close(sock);
        return;
    }

    // Main loop: accept clients and handle them in separate threads
    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            close(sock);
            continue;
        }

        // Create a thread for each client and detach it
        thread clientThread = thread(&ServerBloom::handleClient, this, client_sock);
        clientThread.detach();
    }

    close(sock);
}

