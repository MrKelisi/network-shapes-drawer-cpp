#pragma once

#ifdef WIN32
    #include <winsock2.h>
#else
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <netdb.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
    typedef struct in_addr IN_ADDR;
#endif

class ClientReseau {
    public:
        static ClientReseau& instance();
        virtual ~ClientReseau();
        void setServeur(const char* serveur, unsigned short port);

    private:
        ClientReseau();
        static ClientReseau _instance;

        SOCKET _socket;
};