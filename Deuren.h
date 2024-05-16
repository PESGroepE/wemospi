#ifndef WEMOSPI_DEUREN_H
#define WEMOSPI_DEUREN_H

#include<unistd.h>

#include "TCPSocket.h"

#define aantaldeuren 3

enum Sluisopties {
    DICHT,
    BUITEN,
    BINNEN,
    OPEN
};

class Deuren {
public:
    Deuren(TCPSocket*);
    void openSluis(Sluisopties);
    void openAlles();
    int getStatus(int);
private:
    void openDeur(int);
    void sluitDeur(int);
    void pushStatus();
    int deurstatus[aantaldeuren];

    TCPSocket *socket;
};


#endif //WEMOSPI_DEUREN_H
