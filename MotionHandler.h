#ifndef WEMOSPI_MOTIONHANDLER_H
#define WEMOSPI_MOTIONHANDLER_H

#include "Handler.h"
#include "LEDHandler.h"

/**
 * @brief MotionHandler klasse die gebruikt wordt om de bewegingsensor uit te lezen.
 */
class MotionHandler: public Handler {
public:
    /**
    * Construeer een nieuw MotionHandler object.
    * @brief Constructor.
    */
    MotionHandler(LEDHandler*);

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

private:
    /**
    * Led die bestuurt moet worden door de bewegingsensor.
    */
    LEDHandler *led;
};


#endif //WEMOSPI_MOTIONHANDLER_H
