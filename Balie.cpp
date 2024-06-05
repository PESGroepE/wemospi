#include "Balie.h"
#include <iostream>
#include <thread>
#include <chrono>

Balie::Balie(LEDHandler *l, RelaxstoelHandler *r, Deuren *d) : 
    leds(l), relaxstoel(r), deuren(d),
    knop1(18, 17), knop2(5, 6), knop3(24, 25), 
    knop4(12, 16), knop5(20, 21) {
    bool knopStatus[] = {false, false, false, false, false};
}

void Balie::run(std::string s) {
    while (1) {
        if (knop1.isPressed() && !knopStatus[0]) {
            std::cout << "knop1 ingedrukt" << std::endl;
            bool status = deuren->getStatus(0);
            deuren->setStatus(0, !status);
            knopStatus[0] = true;
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
        } else if (!knop1.isPressed()) {
            knopStatus[0] = false;
        }
        knop1.setStatus(deuren->getStatus(0));

        if (knop2.isPressed() && !knopStatus[1]) {
            std::cout << "knop2 ingedrukt" << std::endl;
            bool status = deuren->getStatus(1);
            deuren->setStatus(1, !status);
            knopStatus[1] = true;
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
        } else if (!knop2.isPressed()) {
            knopStatus[1] = false;
        }
        knop2.setStatus(deuren->getStatus(1));

        if (knop3.isPressed() && !knopStatus[2]) {
            std::cout << "knop3 ingedrukt" << std::endl;
            bool status = deuren->getStatus(2);
            deuren->setStatus(2, !status);
            knopStatus[2] = true;
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
        } else if (!knop3.isPressed()) {
            knopStatus[2] = false;
        }
        knop3.setStatus(deuren->getStatus(2));

        if (knop4.isPressed() && !knopStatus[3]) {
            std::cout << "knop4 ingedrukt" << std::endl;
            bool status = relaxstoel->getTrilmotor();
            relaxstoel->setTrilmotor(!status);
            knopStatus[3] = true;
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
        } else if (!knop4.isPressed()) {
            knopStatus[3] = false;
        }
        knop4.setStatus(relaxstoel->getTrilmotor());

        if (knop5.isPressed() && !knopStatus[4]) {
            std::cout << "knop5 ingedrukt" << std::endl;
            bool status = leds->getStatus();
            leds->setStatus(!status);
            knopStatus[4] = true;
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
        } else if (!knop5.isPressed()) {
            knopStatus[4] = false;
        }
        knop5.setStatus(leds->getStatus());
    }
}