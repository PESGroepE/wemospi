#include "Webserver.h"

Webserver::Webserver(std::string l, int p):listener(l),port(p),svr() {}

void Webserver::listen(std::string n) {
    svr.listen(listener, port);
}

void Webserver::addGetHandler(Handler *handler) {
    handler->get(&svr);
}

void Webserver::addPostHandler(Handler *handler) {
    handler->post(&svr);
}