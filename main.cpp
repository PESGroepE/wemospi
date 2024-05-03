/**
@file main.cpp
*/

#include <iostream>

#include "Webserver.h"
#include "RFIDHandler.h"
#include "MotionHandler.h"
#include "MatrixHandler.h"
#include "LEDHandler.h"

#define LISTENER "0.0.0.0"
#define PORT 8080

/**
 * @brief main functie van het programma.
 * Functie die alle handlers aanmaakt en deze koppelt aan de webserver. Ook is hier de cli geimplementeerd.
 */
int main() {
    std::cout << "PES Groep E Wemos Pi" << std::endl;

    std::cout << "Creating handlers..." << std::endl;
    LEDHandler led;
    MotionHandler motion(&led);
    MatrixHandler matrix;
    RFIDHandler rfid("abcd", &matrix);

    std::cout << "Registering webserver listeners..." << std::endl;
    Webserver ws (LISTENER, PORT);
    ws.addPostHandler(&rfid);
    ws.addPostHandler(&motion);
    ws.addGetHandler(&matrix);
    ws.addGetHandler(&led);

    std::cout << "Starting listener on " << LISTENER << ":" << PORT << std::endl;
    std::thread t1(&Webserver::listen, &ws, "params");

    std::cout << "Ready to receive commands." << std::endl;
    while(1) {
        std::cout << "input key: ";
        std::string key;
        std::cin>>key;

        std::cout << "input value: ";
        std::string value;
        std::cin>>value;

        if (key=="led") {
            if (value=="true") led.setStatus(true);
            if (value=="false") led.setStatus(false);
            continue;
        }

        if (key=="matrix") {
            matrix.setMessage(value);
            continue;
        }

    }

    return 0;
}
