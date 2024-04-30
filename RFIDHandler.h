#ifndef WEMOSPI_RFIDHANDLER_H
#define WEMOSPI_RFIDHANDLER_H

#include "Handler.h"

class RFIDHandler: public Handler {
public:
    RFIDHandler(std::string);
    void get(httplib::Server*);
    void post(httplib::Server*);
private:
    std::string valid;
};

#endif //WEMOSPI_RFIDHANDLER_H
