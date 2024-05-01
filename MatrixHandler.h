#ifndef WEMOSPI_MATRIXHANDLER_H
#define WEMOSPI_MATRIXHANDLER_H


#include "Handler.h"

class MatrixHandler: public Handler {
public:
    MatrixHandler();
    void get(httplib::Server*);
    void post(httplib::Server*);
    void setMessage(std::string);
    std::string getMessage() const;
private:
    std::string msg;
};


#endif //WEMOSPI_MATRIXHANDLER_H
