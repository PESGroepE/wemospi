#ifndef WEMOSPI_TCPSOCKET_H
#define WEMOSPI_TCPSOCKET_H

#include <string>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

#include "Event.h"

class TCPSocket {
public:
    TCPSocket(int);
    int init();
    void handle(Event*);
    void sendMessage(std::string);

private:
    int port;
    int serverSocket;
    int clientSocket;
    sockaddr_in serverAddress;

};


#endif //WEMOSPI_TCPSOCKET_H
