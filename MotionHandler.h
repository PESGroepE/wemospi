#ifndef WEMOSPI_MOTIONHANDLER_H
#define WEMOSPI_MOTIONHANDLER_H

#include "Handler.h"
#include "LEDHandler.h"

class MotionHandler: public Handler {
public:
    MotionHandler(LEDHandler*);
    void get(httplib::Server*);
    void post(httplib::Server*);
private:
    LEDHandler *led;
};


#endif //WEMOSPI_MOTIONHANDLER_H
