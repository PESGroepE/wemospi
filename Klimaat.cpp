#include "Klimaat.h"

Klimaat::Klimaat(Deuren* d, TCPSocket* s, LEDHandler* l):deuren(d),socket(s),leds(l),brand(false),lucht(false) {

}

void Klimaat::handleEvent(Event *e) {
    float val = std::stof(e->getData());
    switch (e->getType()) {
        case TEMP:
            checkBrand(val);
            break;
        case HUMIDITY:
            checkLucht(val);
            break;
    }
}

void Klimaat::checkBrand(float temp) {
    if (temp >= 26.0) {
        brand = true;
        deuren->openAlles();
        socket->sendMessage("brand:1");
        leds->setBrand(true);
    } else if (brand) {
        brand = false;
        deuren->sluitAlles();
        socket->sendMessage("brand:0");
        leds->setBrand(false);
    }
}

void Klimaat::checkLucht(float humid) {
    if (humid >= 80.0) {
        lucht = true;
        deuren->openSluis(OPEN);
    } else if (lucht) {
        lucht = false;
        deuren->openSluis(DICHT);
    }
}
