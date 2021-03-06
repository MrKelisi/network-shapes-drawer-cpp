#include "clientreseau.h"
#include "exceptions/socketexception.h"

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
            throw SocketException("WSAStartup failed !");
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