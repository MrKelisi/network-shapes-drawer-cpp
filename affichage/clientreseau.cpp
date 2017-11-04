#include <stdexcept>
#include "clientreseau.h"

#ifdef _WIN32
    #include <winsock2.h>
    #include <Ws2tcpip.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <unistd.h>
#include <stdexcept>
#include <cstring>
#include <iostream>

#endif

ClientReseau ClientReseau::_instance;

ClientReseau::ClientReseau() {
    #ifdef WIN32
        WSADATA wsa;
        if(WSAStartup(MAKEWORD(2, 2), &wsa) < 0) {
            throw std::runtime_error("WSAStartup failed !"); //TODO: exception
        }
    #endif
}

ClientReseau::~ClientReseau() {
    #ifdef _WIN32
        WSACleanup();
    #endif
}

ClientReseau& ClientReseau::instance() {
    return ClientReseau::_instance;
}