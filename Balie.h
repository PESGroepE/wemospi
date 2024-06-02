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

/**
 * @brief Balie klasse die gebruikt wordt voor de bediening van het systeem d.m.v. ledknoppen.
 */
class Balie {
public:
    /**
    * Construeer een nieuw Balie object.
    * @brief Constructor.
    * @param leds Pointer naar de LEDHandler.
    * @param relaxstoel Pointer naar de RelaxstoelHandler.
    * @param deuren Pointer naar de Deuren.
    */
    Balie(LEDHandler*, RelaxstoelHandler*, Deuren*);

    /**
    * @brief Functie die constant de knoppen update.
    */
    void run(std::string);
private:
    /**
    * Pointer naar de LEDHandler.
    */
    LEDHandler *leds;

    /**
    * Pointer naar de RelaxstoelHandler.
    */
    RelaxstoelHandler *relaxstoel;

    /**
    * Pointer naar de Deuren.
    */
    Deuren *deuren;

    /**
    * Knop1 (deur0)
    */
    Button knop1;

    /**
    * Knop2 (deur1)
    */
    Button knop2;

    /**
    * Knop3 (deur2)
    */
    Button knop3;

    /**
    * Knop4 (relaxstoel)
    */
    Button knop4;

    /**
    * Knop5 (leds)
    */
    Button knop5;
};


#endif //WEMOSPI_BALIE_H
