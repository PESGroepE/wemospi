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

    /**
    * @brief Stel de status van de trilmotor in.
    * @param status Boolean die de status van de trilmotor
    */
    void setTrilmotor(bool);

    /**
    * @brief Haal de status van de trilmotor op.
    */
    bool getTrilmotor() const;

private:
    /**
    * Status van de trilmotor.
    */
    bool motor;

    /**
    * Status van de knop.
    */
    bool knop;
};

#endif //WEMOSPI_RELAXSTOELHANDLER_H
