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

/**
 * @brief TCPSocket klasse die gebruikt wordt om berichten uit te wisselen met de andere pi.
 */
class TCPSocket {
public:
    /**
    * Construeer een nieuw TCPSocket object.
    * @brief Constructor.
    * @param port Poort waarop geluisterd moet worden.
    */
    TCPSocket(int);

    /**
    * @brief Initialiseer de socket door de listener te starten.
    */
    int init();

    /**
    * @brief Behandel nieuwe berichten die op de socket binnenkomen.
    */
    void handle(Event*);

    /**
    * @brief Stuur een bericht over de socket.
    * @param msg String met bericht wat de socket over moet.
    */
    void sendMessage(std::string);

private:
    /**
    * Poort waar op geluisterd moet worden.
    */
    int port;

    /**
    * Remote adres van de socket.
    */
    int serverSocket;

    /**
    * Lokaal adres van de socket.
    */
    int clientSocket;

    /**
    * Adres waarop de socket moet luisteren.
    */
    sockaddr_in serverAddress;

};


#endif //WEMOSPI_TCPSOCKET_H
