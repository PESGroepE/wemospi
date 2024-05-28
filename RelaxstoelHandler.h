#ifndef WEMOSPI_RELAXSTOELHANDLER_H
#define WEMOSPI_RELAXSTOELHANDLER_H

#include "Handler.h"

class RelaxstoelHandler: public Handler {
public:
    RelaxstoelHandler();
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

    void setTrilmotor(bool);

    bool getTrilmotor() const;

private:
    bool motor;
};

#endif //WEMOSPI_RELAXSTOELHANDLER_H
