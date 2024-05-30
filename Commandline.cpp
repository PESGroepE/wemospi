#include "Commandline.h"

Commandline::Commandline(LEDHandler *l, MatrixHandler *m):leds(l),matrix(m) {
}

void Commandline::listen(std::string s) {
    while (1) {
        std::cout << "input key: ";
        std::string key;
        std::cin >> key;

        std::cout << "input value: ";
        std::string value;
        std::cin >> value;

        if (key == "led") {
            if (value == "true") leds->setStatus(true);
            if (value == "false") leds->setStatus(false);
            continue;
        }

        if (key == "kleur") {
            leds->setKleur(value);
            continue;
        }

        if (key == "matrix") {
            matrix->setMessage(value);
            continue;
        }
    }
}


