/**
@file Deuren.cpp
*/

#include "Deuren.h"

Deuren::Deuren(TCPSocket* t):socket(t) {
    for (int i=0; i<aantaldeuren; i++) {
        sluitDeur(i);
    }
}

void Deuren::openSluis(Sluisopties o) {
    switch (o) {
        case BUITEN:
            std::cout<<"begin sluis openen"<<std::endl;
            openDeur(0);
            sleep(3);
            sluitDeur(0);

            sleep(1);

            openDeur(1);
            sleep(3);
            sluitDeur(1);

            break;
        case BINNEN:
            openDeur(1);
            sleep(3);
            sluitDeur(1);

            sleep(1);

            openDeur(0);
            sleep(3);
            sluitDeur(0);

            break;
        case OPEN:
            openDeur(0);
            openDeur(1);
            break;
        case DICHT:
            sluitDeur(0);
            sluitDeur(1);
            break;
    }
}

void Deuren::openAlles() {
    for (int i=0; i<aantaldeuren; i++) {
        openDeur(i);
    }
}

void Deuren::openDeur(int d) {
    deurstatus[d] = 1;
    pushStatus();
}

void Deuren::sluitDeur(int d) {
    deurstatus[d] = 0;
    pushStatus();
}

int Deuren::getStatus(int d) {
    return deurstatus[d];
}

void Deuren::pushStatus() {
    std::string msg = "deuren:";
    for (int status : deurstatus) {
        msg += std::to_string(status);
    }
    socket->sendMessage(msg);
}
