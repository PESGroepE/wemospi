#ifndef WEMOSPI_COMMANDLINE_H
#define WEMOSPI_COMMANDLINE_H

#include "LEDHandler.h"
#include "MatrixHandler.h"

class Commandline {
public:
    Commandline(LEDHandler*, MatrixHandler*);
    void listen(std::string);
private:
    LEDHandler *leds;
    MatrixHandler *matrix;
};

#endif //WEMOSPI_COMMANDLINE_H
