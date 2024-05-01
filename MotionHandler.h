#ifndef WEMOSPI_MOTIONHANDLER_H
#define WEMOSPI_MOTIONHANDLER_H

#include "Handler.h"

class MotionHandler: public Handler {
public:
    MotionHandler();
    void get(httplib::Server*);
    void post(httplib::Server*);
};


#endif //WEMOSPI_MOTIONHANDLER_H
