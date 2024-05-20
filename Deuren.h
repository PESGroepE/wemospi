#ifndef WEMOSPI_DEUREN_H
#define WEMOSPI_DEUREN_H

#include<unistd.h>

#include "TCPSocket.h"

#define aantaldeuren 3

enum Sluisopties {
    DICHT,
    BUITEN,
    BINNEN,
    OPEN
};

/**
 * @brief Deuren klasse die gebruikt wordt om de deuren aan te sturen.
 */
class Deuren {
public:
    /**
    * Construeer een nieuw Deuren object.
    * @brief Constructor.
    * @param socket TCPsocket die wordt gebruikt voor de aansturing.
    */
    Deuren(TCPSocket*);

    /**
    * @brief Open de sluis.
    * @param opties Enum om te kiezen in welke richting de sluis open moet.
    */
    void openSluis(Sluisopties);

    /**
    * @brief Open alle deuren.
    */
    void openAlles();

    /**
    * @brief Vraag de status van een van de deuren op.
    * @param nummer Nummer van de deur.
    */
    int getStatus(int);

private:
    /**
    * @brief Open een deur.
    * @param nummer Nummer van de deur.
    */
    void openDeur(int);

    /**
    * @brief Sluit een deur.
    * @param nummer Nummer van de deur.
    */
    void sluitDeur(int);

    /**
    * @brief Verstuur de status van de deuren over de socket-verbinding.
    */
    void pushStatus();

    /**
    * @brief Array die de status van de deuren opslaat.
    */
    int deurstatus[aantaldeuren];

    /**
    * @brief Pointer naar de TCPsocket die wordt gebruikt voor de aansturing.
    */
    TCPSocket *socket;
};


#endif //WEMOSPI_DEUREN_H
