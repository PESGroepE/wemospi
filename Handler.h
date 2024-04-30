#ifndef WEMOSPI_HANDLER_H
#define WEMOSPI_HANDLER_H

#include "httplib.h"
#include "Webserver.h"

class Handler {
public:
    Handler();
    virtual void get(httplib::Server*)=0;
    virtual void post(httplib::Server*)=0;
};


#endif //WEMOSPI_HANDLER_H
