#ifndef WEMOSPI_COMMANDLINE_H
#define WEMOSPI_COMMANDLINE_H

#include "LEDHandler.h"
#include "MatrixHandler.h"

/**
 * @brief Commandline klasse die gebruikt wordt voor de bediening via de cli.
 */
class Commandline {
public:
    /**
    * Construeer een nieuw Commandline object.
    * @brief Constructor.
    * @param leds Pointer naar de LEDHandler.
    * @param matrix Pointer naar de MatrixHandler.
    */
    Commandline(LEDHandler*, MatrixHandler*);

    /**
    * @brief Functie die wacht op nieuwe commando's.
    */
    void listen(std::string);
private:
    /**
    * Pointer naar de LEDHandler.
    */
    LEDHandler *leds;

    /**
    * Pointer naar de MatrixHandler.
    */
    MatrixHandler *matrix;
};

#endif //WEMOSPI_COMMANDLINE_H
