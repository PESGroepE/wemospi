#ifndef WEMOSPI_WEBSERVER_H
#define WEMOSPI_WEBSERVER_H

#include "httplib.h"
#include "Handler.h"
#include <string>

class Handler;
class Webserver {
public:
    Webserver(std::string, int);
    void listen(std::string);
    void addGetHandler(Handler*);
    void addPostHandler(Handler*);

private:
    httplib::Server svr;
    std::string listener;
    int port;
};


#endif //WEMOSPI_WEBSERVER_H
