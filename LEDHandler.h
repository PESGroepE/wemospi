#ifndef WEMOSPI_LEDHANDLER_H
#define WEMOSPI_LEDHANDLER_H

#include "Handler.h"

class LEDHandler: public Handler {
    public:
        LEDHandler();

        void get(httplib::Server*);
        void post(httplib::Server*);

        void setStatus(bool);
        bool getStatus() const;
    private:
        bool status;
};


#endif //WEMOSPI_LEDHANDLER_H
