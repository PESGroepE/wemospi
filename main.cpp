/**
@file main.cpp
*/

#include <iostream>

#include "Webserver.h"
#include "RFIDHandler.h"
#include "MatrixHandler.h"
#include "LEDHandler.h"
#include "TCPSocket.h"
#include "Event.h"
#include "Deuren.h"
#include "Klimaat.h"
#include "RelaxstoelHandler.h"
#include "Commandline.h"
#include "Balie.h"

#define LISTENER "0.0.0.0"
#define PORT 8080

TCPSocket *sock = new TCPSocket(5000);

Deuren *d = new Deuren(sock);
LEDHandler *led = new LEDHandler;
MatrixHandler *matrix = new MatrixHandler;
RelaxstoelHandler *relaxstoel = new RelaxstoelHandler;
RFIDHandler *rfid = new RFIDHandler("abcd", matrix, d);
Klimaat *klimaat = new Klimaat(d, sock, led);
Commandline cli(led, matrix);

/**
 * @brief main functie van het programma.
 * Functie die alle handlers aanmaakt en deze koppelt aan de webserver. Ook is hier de cli geimplementeerd.
 */
int main() {
    std::cout << "PES Groep E Wemos Pi" << std::endl;

    std::cout << "Creating handlers..." << std::endl;

    sock->init();

    std::cout << "Registering webserver listeners..." << std::endl;
    Webserver ws(LISTENER, PORT);
    ws.addPostHandler(rfid);
    ws.addGetHandler(matrix);
    ws.addGetHandler(led);
    ws.addGetHandler(relaxstoel);
    ws.addPostHandler(relaxstoel);

    std::cout << "Starting listener on " << LISTENER << ":" << PORT << std::endl;
    std::thread t1(&Webserver::listen, &ws, "params");

    std::thread t2(&Commandline::listen, &cli, "params");
    std::cout << "Ready to receive commands." << std::endl;

    if (wiringPiSetupGpio() == -1) {
        std::cerr << "Error initializing WiringPi" << std::endl;
    }
    Balie balie(led, relaxstoel, d);
    std::thread t3(&Balie::run, &balie, "params");
    std::cout << "Started balie thread" << std::endl;

    while (1) {
        Event *event = new Event();
        sock->handle(event);

        switch (event->getType()) {
            case HUMIDITY:
                matrix->setMessage(event->getData());
                klimaat->handleEvent(event);
                break;
            case TEMP:
                klimaat->handleEvent(event);
                break;
            case NOODKNOP:
                d->openSluis(OPEN);
                klimaat->handleEvent(event);
                break;
            case SLUISKNOP:
                d->openSluis(BINNEN);
                break;
            case BEWEGINGLAMPEN:
                if (event->getData()[0]=='1') {
                    led->setStatus(true);
                } else {
                    led->setStatus(false);
                }
                break;
            case BEWEGINGDEUR:
                if (event->getData()[0]=='1') {
                    d->setStatus(2, true);
                } else {
                    d->setStatus(2, false);
                }
                break;
        }
    }

    return 0;
}
