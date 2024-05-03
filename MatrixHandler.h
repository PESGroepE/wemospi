#ifndef WEMOSPI_MATRIXHANDLER_H
#define WEMOSPI_MATRIXHANDLER_H

#include "Handler.h"

/**
 * @brief MatrixHandler klasse die gebruikt wordt om de matrix/lichtkrant aan te sturen.
 */
class MatrixHandler: public Handler {
public:
    /**
    * Construeer een nieuw MatrixHandler object.
    * @brief Constructor.
    */
    MatrixHandler();

    /**
    * @brief Roep een get handler aan.
    * @param svr Pointer naar de httpserver.
    */
    void get(httplib::Server*);

    /**
    * @brief Roep een post handler aan.
    * @param svr Pointer naar de httpserver.
    */
    void post(httplib::Server*);

    /**
    * @brief Stel het bericht van de matrix/lichtkrant in.
    * @param msg Bericht wat getoond moet worden.
    */
    void setMessage(std::string);

    /**
    * @brief Haal het bericht van de matrix/lichtkrant op.
    */
    std::string getMessage() const;

private:
    /**
    * Bericht van de matrix/lichtkrant.
    */
    std::string msg;
};


#endif //WEMOSPI_MATRIXHANDLER_H
