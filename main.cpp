#include <iostream>

#include "Webserver.h"
#include "RFIDHandler.h"

#define LISTENER "0.0.0.0"
#define PORT 8080

int main() {
    std::cout << "PES Groep E Wemos Pi" << std::endl;

    std::cout << "Creating handlers..." << std::endl;
    RFIDHandler rfid("abcd");

    std::cout << "Registering webserver listeners..." << std::endl;
    Webserver ws(LISTENER, PORT);
    ws.addPostHandler(&rfid);

    std::cout << "Starting listener on " << LISTENER << ":" << PORT << std::endl;
    ws.listen();

    return 0;
}
