#ifndef WEMOSPI_KLIMAAT_H
#define WEMOSPI_KLIMAAT_H

#include "Event.h"
#include "Deuren.h"
#include "LEDHandler.h"

class Klimaat {
public:
    Klimaat(Deuren*, TCPSocket*, LEDHandler*);
    void handleEvent(Event*);

private:
    void checkBrand(float);

    void checkLucht(float);

    Deuren *deuren;
    TCPSocket *socket;
    LEDHandler *leds;

    bool brand;
    bool lucht;
};

#endif //WEMOSPI_KLIMAAT_H
