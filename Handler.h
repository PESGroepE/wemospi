#ifndef WEMOSPI_HANDLER_H
#define WEMOSPI_HANDLER_H

#include "httplib.h"
#include "Webserver.h"

/**
 * @brief Handler klasse voor het afhandelen van HTTP requests
 */
class Handler {
public:
    /**
    * Construeer een nieuw Handler object.
    * @brief Constructor.
    */
    Handler();

    /**
    * @brief Roep een get handler aan.
    * @param svr Pointer naar de httpserver.
    */
    virtual void get(httplib::Server*)=0;

    /**
    * @brief Roep een post handler aan.
    * @param svr Pointer naar de httpserver.
    */
    virtual void post(httplib::Server*)=0;
};


#endif //WEMOSPI_HANDLER_H
