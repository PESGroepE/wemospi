/**
@file TCPSocket.cpp
*/

#include "TCPSocket.h"

TCPSocket::TCPSocket(int p):port(p) {

}

int TCPSocket::init() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddress,
         sizeof(serverAddress));

    listen(serverSocket, 5);

    clientSocket = accept(serverSocket, nullptr, nullptr);

    return 0;
}

void TCPSocket::handle(Event *e) {
    char buffer[256] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);

    std::string data = buffer;
    int d = data.find(':');
    if (data.substr(0, d)=="humidity") {
        e->setType(HUMIDITY);
        e->setData(data.substr(d+1, data.size()));
    }
    if (data.substr(0, d)=="noodknop") {
        e->setType(NOODKNOP);
        e->setData(data.substr(d+1, data.size()));
    }
    if (data.substr(0, d)=="sluisknop") {
        e->setType(SLUISKNOP);
        e->setData(data.substr(d+1, data.size()));
    }
    if (data.substr(0, d)=="temp") {
        e->setType(TEMP);
        e->setData(data.substr(d+1, data.size()));
    }
    if (data.substr(0, d)=="beweginglampen") {
        e->setType(BEWEGINGLAMPEN);
        e->setData(data.substr(d+1, data.size()));
    }
    if (data.substr(0, d)=="bewegingdeur") {
        e->setType(BEWEGINGDEUR);
        e->setData(data.substr(d+1, data.size()));
    }
}

void TCPSocket::sendMessage(std::string msg) {
    send(clientSocket, msg.c_str(), strlen(msg.c_str()),  0);
}
