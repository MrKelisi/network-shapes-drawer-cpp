#pragma once

#include <vector>
#include <string>

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

    private:
        ClientReseau();
        virtual ~ClientReseau();
        ClientReseau(const ClientReseau& other);
        ClientReseau operator = (const ClientReseau& other);

        static ClientReseau _instance;
};