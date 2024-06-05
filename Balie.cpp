#include "Balie.h"
#include <iostream>
#include <thread>
#include <chrono>

Balie::Balie(LEDHandler *l, RelaxstoelHandler *r, Deuren *d) : 
    leds(l), relaxstoel(r), deuren(d),
    knop1(18, 17), knop2(5, 6), knop3(24, 25), 
    knop4(12, 16), knop5(20, 21) { 
}

void Balie::run(std::string s) {
    bool knop1WasIngedrukt = false;
    bool knop2WasIngedrukt = false;
    bool knop3WasIngedrukt = false;
    bool knop4WasIngedrukt = false;
    bool knop5WasIngedrukt = false;

    while (1) {
        if (knop1.isPressed() && !knop1WasIngedrukt) {
            std::cout << "knop1 ingedrukt" << std::endl;
            bool status = deuren->getStatus(0);
            deuren->setStatus(0, !status);
            knop1WasIngedrukt = true;
        } else if (!knop1.isPressed()) {
            knop1WasIngedrukt = false;
        }
        knop1.setStatus(deuren->getStatus(0));

        if (knop2.isPressed() && !knop2WasIngedrukt) {
            std::cout << "knop2 ingedrukt" << std::endl;
            bool status = deuren->getStatus(1);
            deuren->setStatus(1, !status);
            knop2WasIngedrukt = true;
        } else if (!knop2.isPressed()) {
            knop2WasIngedrukt = false;
        }
        knop2.setStatus(deuren->getStatus(1));

        if (knop3.isPressed() && !knop3WasIngedrukt) {
            std::cout << "knop3 ingedrukt" << std::endl;
            bool status = deuren->getStatus(2);
            deuren->setStatus(2, !status);
            knop3WasIngedrukt = true;
        } else if (!knop3.isPressed()) {
            knop3WasIngedrukt = false;
        }
        knop3.setStatus(deuren->getStatus(2));

        if (knop4.isPressed() && !knop4WasIngedrukt) {
            std::cout << "knop4 ingedrukt" << std::endl;
            bool status = relaxstoel->getTrilmotor();
            relaxstoel->setTrilmotor(!status);
            knop4WasIngedrukt = true;
        } else if (!knop4.isPressed()) {
            knop4WasIngedrukt = false;
        }
        knop4.setStatus(relaxstoel->getTrilmotor());

        if (knop5.isPressed() && !knop5WasIngedrukt) {
            std::cout << "knop5 ingedrukt" << std::endl;
            bool status = leds->getStatus();
            leds->setStatus(!status);
            knop5WasIngedrukt = true;
        } else if (!knop5.isPressed()) {
            knop5WasIngedrukt = false;
        }
        knop5.setStatus(leds->getStatus());

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    }
}
