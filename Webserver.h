#ifndef WEMOSPI_WEBSERVER_H
#define WEMOSPI_WEBSERVER_H

#include "httplib.h"
#include "Handler.h"
#include <string>

class Handler;

/**
 * @brief Webserver klasse die ervoor zorgt dat de applicatie via http bereikbaar is.
 */
class Webserver {
public:
    /**
    * Construeer een nieuw RFIDHandler object.
    * @brief Constructor.
    * @param listener String met het ip waarop geluisterd moet worden.
    * @param port Int van het poortnummer.
    */
    Webserver(std::string, int);

    /**
    * @brief Functie die begint met luisteren voor connecties.
    */
    void listen(std::string);

    /**
    * @brief Voeg een get handler toe aan de webserver.
    * @param handler Pointer naar de handler die toegevoegd moet worden.
    */
    void addGetHandler(Handler*);

    /**
    * @brief Voeg een post handler toe aan de webserver.
    * @param handler Pointer naar de handler die toegevoegd moet worden.
    */
    void addPostHandler(Handler*);
private:
    /**
    * Interne HTTP server.
    */
    httplib::Server svr;

    /**
    * String met het ip waarop geluisterd moet worden.
    */
    std::string listener;

    /**
    * Int van het poortnummer.
    */
    int port;
};


#endif //WEMOSPI_WEBSERVER_H
