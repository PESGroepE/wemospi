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
            pushStatus();

            sleep(3);

            sluitDeur(0);
            pushStatus();

            sleep(1);

            openDeur(1);
            pushStatus();

            sleep(3);

            sluitDeur(1);
            pushStatus();

            break;
        case BINNEN:
            openDeur(1);
            pushStatus();
            sleep(3);
            sluitDeur(1);
            pushStatus();

            sleep(1);

            openDeur(0);
            pushStatus();

            sleep(3);

            sluitDeur(0);
            pushStatus();

            break;
        case OPEN:
            openDeur(0);
            openDeur(1);

            pushStatus();
            break;
        case DICHT:
            sluitDeur(0);
            sluitDeur(1);

            pushStatus();
            break;
    }
}

void Deuren::openAlles() {
    for (int i=0; i<aantaldeuren; i++) {
        openDeur(i);
    }
    pushStatus();
}

void Deuren::sluitAlles() {
    for (int i=0; i<aantaldeuren; i++) {
        sluitDeur(i);
    }
    pushStatus();
}

void Deuren::openDeur(int d) {
    deurstatus[d] = 1;
}

void Deuren::sluitDeur(int d) {
    deurstatus[d] = 0;
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
