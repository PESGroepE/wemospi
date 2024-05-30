#include "Balie.h"

Balie::Balie(LEDHandler *l, RelaxstoelHandler *r, Deuren *d):leds(l),relaxstoel(r),deuren(d),
                knop1(18,17), knop2(5,6), knop3(24,25), knop4(12,16), knop5(20,21) {
}

void Balie::run(std::string s) {
    while (1) {
        if (knop1.isPressed()) {
            std::cout<<"knop1 ingedrukt"<<std::endl;
            bool status = deuren->getStatus(0);
            deuren->setStatus(0, !status);
        }

        if (knop2.isPressed()) {
            std::cout<<"knop2 ingedrukt"<<std::endl;
            bool status = deuren->getStatus(1);
            deuren->setStatus(1, !status);
        }

        if (knop3.isPressed()) {
            std::cout<<"knop3 ingedrukt"<<std::endl;
            bool status = deuren->getStatus(2);
            deuren->setStatus(2, !status);
        }

        if (knop4.isPressed()) {
            std::cout<<"knop4 ingedrukt"<<std::endl;
            bool status = relaxstoel->getTrilmotor();
            relaxstoel->setTrilmotor(!status);
        }

        if (knop5.isPressed()) {
            std::cout<<"knop5 ingedrukt"<<std::endl;
            bool status = leds->getStatus();
            leds->setStatus(!status);
        }

        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

