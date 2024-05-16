/**
@file main.cpp
*/

#include <iostream>

#include "Webserver.h"
#include "RFIDHandler.h"
#include "MotionHandler.h"
#include "MatrixHandler.h"
#include "LEDHandler.h"
#include "Button.h"
#include <wiringPi.h>
#include "TCPSocket.h"
#include "Event.h"
#include "Deuren.h"

#define LISTENER "0.0.0.0"
#define PORT 8080

TCPSocket sock(5000);

Deuren d(&sock);
LEDHandler led;
MotionHandler motion(&led);
MatrixHandler matrix;
RFIDHandler rfid("abcd", &matrix, &d);

/**
 * @brief main functie van het programma.
 * Functie die alle handlers aanmaakt en deze koppelt aan de webserver. Ook is hier de cli geimplementeerd.
 */
int main() {
    std::cout << "PES Groep E Wemos Pi" << std::endl;

    std::cout << "Creating handlers..." << std::endl;

    sock.init();

    std::cout << "Registering webserver listeners..." << std::endl;
    Webserver ws(LISTENER, PORT);
    ws.addPostHandler(&rfid);
    ws.addPostHandler(&motion);
    ws.addGetHandler(&matrix);
    ws.addGetHandler(&led);

    std::cout << "Starting listener on " << LISTENER << ":" << PORT << std::endl;
    std::thread t1(&Webserver::listen, &ws, "params");

    std::cout << "Ready to receive commands." << std::endl;

    if (wiringPiSetupGpio() == -1) {
        std::cerr << "Error initializing WiringPi" << std::endl;
        return 1;
    }
    Button butt1(18, 17);

    while (1) {
        Event *event = new Event();
        sock.handle(event);

        switch (event->getType()) {
            case HUMIDITY:
                matrix.setMessage(event->getData());
                break;
        }
    }
    /*
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
    */

    return 0;
}
