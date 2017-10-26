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

    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if(_socket == INVALID_SOCKET) {
        throw std::runtime_error("Socket"); //TODO: exception
    }
}

ClientReseau::~ClientReseau() {


    #ifdef _WIN32
        WSACleanup();
    #endif
}

ClientReseau& ClientReseau::instance() {
    return ClientReseau::_instance;
}

void ClientReseau::setServeur(const char* serveur, unsigned short port) {
    struct hostent *hostinfo = NULL;
    SOCKADDR_IN sin = { 0 };

    hostinfo = gethostbyname(serveur); /* on récupère les informations de l'hôte auquel on veut se connecter */
    if (hostinfo == NULL) /* l'hôte n'existe pas */
    {
        fprintf (stderr, "Unknown host %s.\n", serveur);
        exit(EXIT_FAILURE);
    }

    sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
    sin.sin_port = htons(port); /* on utilise htons pour le port */
    sin.sin_family = AF_INET;

    if(connect(_socket,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        perror("connect()");
        exit(errno);
    }

    char buffer[1024] = "Bonsoir\n";
    if(send(_socket, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }

    ssize_t n = 0;
    if((n = recv(_socket, buffer, sizeof(buffer) - 1, 0)) < 0)
    {
        perror("recv()");
        exit(errno);
    }

    std::cout << buffer << std::endl;
}
