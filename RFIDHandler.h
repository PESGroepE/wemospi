#ifndef WEMOSPI_RFIDHANDLER_H
#define WEMOSPI_RFIDHANDLER_H

#include "Handler.h"
#include "MatrixHandler.h"
#include "Deuren.h"

/**
 * @brief RFIDHandler klasse die gebruikt wordt om de rfid-scanner uit te lezen.
 */
class RFIDHandler: public Handler {
public:
    /**
    * Construeer een nieuw RFIDHandler object.
    * @brief Constructor.
    * @param valid String met geldig ID.
    * @param matrix Pointer naar MatrixHandler.
    */
    RFIDHandler(std::string, MatrixHandler*, Deuren*);

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
private:
    /**
    * Geldig ID om input mee te controleren.
    */
    std::string valid;

    /**
    * MatrixHandler om aan te sturen.
    */
    MatrixHandler *matrix;

    Deuren *deuren;
};

#endif //WEMOSPI_RFIDHANDLER_H
