#include <iostream>

#include "Webserver.h"
#include "RFIDHandler.h"
#include "MotionHandler.h"
#include "MatrixHandler.h"
#include "LEDHandler.h"

#define LISTENER "0.0.0.0"
#define PORT 8080

int main() {
    std::cout << "PES Groep E Wemos Pi" << std::endl;

    std::cout << "Creating handlers..." << std::endl;
    LEDHandler led;
    MotionHandler motion(&led);
    MatrixHandler matrix;
    RFIDHandler rfid("abcd", &matrix);

    std::cout << "Registering webserver listeners..." << std::endl;
    Webserver ws(LISTENER, PORT);
    ws.addPostHandler(&rfid);
    ws.addPostHandler(&motion);
    ws.addGetHandler(&matrix);
    ws.addGetHandler(&led);

    std::cout << "Starting listener on " << LISTENER << ":" << PORT << std::endl;
    ws.listen();

    return 0;
}
