#ifndef WEMOSPI_RFIDHANDLER_H
#define WEMOSPI_RFIDHANDLER_H

#include "Handler.h"
#include "MatrixHandler.h"

class RFIDHandler: public Handler {
public:
    RFIDHandler(std::string, MatrixHandler*);
    void get(httplib::Server*);
    void post(httplib::Server*);
private:
    std::string valid;
    MatrixHandler *matrix;
};

#endif //WEMOSPI_RFIDHANDLER_H
