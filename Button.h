#ifndef BUTTON_H
#define BUTTON_H

#include <wiringPi.h>

/**
 * @brief Button klasse die gebruikt wordt voor communicatie met de STM32's.
 */
class Button {
public:
    /**
    * Construeer een nieuw Button object.
    * @brief Constructor.
    * @param ledPin Pin nummer van de led.
    * @param sw1Pin Pin nummer van de knop.
    */
    Button(int ledPin, int sw1Pin);

    /**
    * @brief Functie om de status op te vragen
    */
    void setStatus(bool);

    /**
    * @brief Functie die teruggeeft of de knop is ingedrukt.
    */
    bool isPressed() const;

private:
    /**
    * @brief Pin nummer van de led.
    */
    int ledPin;

    /**
    * @brief Pin nummer van de knop.
    */
    int sw1Pin;
};

#endif
