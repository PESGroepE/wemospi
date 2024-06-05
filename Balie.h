#ifndef WEMOSPI_BALIE_H
#define WEMOSPI_BALIE_H

#include "Button.h"
#include "RelaxstoelHandler.h"
#include "Deuren.h"
#include "LEDHandler.h"

#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPi.h>

class Balie {
public:
    Balie(LEDHandler*, RelaxstoelHandler*, Deuren*);
    void run(std::string);
private:
    LEDHandler *leds;
    RelaxstoelHandler *relaxstoel;
    Deuren *deuren;

    Button knop1;
    Button knop2;
    Button knop3;
    Button knop4;
    Button knop5;
    
    bool knopStatus[5]; 
};


#endif //WEMOSPI_BALIE_H