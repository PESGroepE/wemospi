#include "Button.h"
#include <wiringPi.h>

Button::Button(int ledPin, int sw1Pin) :
    ledPin(ledPin),
    sw1Pin(sw1Pin)
{
    pinMode(ledPin, OUTPUT);
    pinMode(sw1Pin, INPUT);
    pullUpDnControl(sw1Pin, PUD_UP);
}

void Button::setStatus(bool b) {
    digitalWrite(ledPin, b ? HIGH : LOW);
}

bool Button::isPressed() const {
    if (digitalRead(sw1Pin) == LOW) {
        delay(60);
        if (digitalRead(sw1Pin) == LOW) {
            return true;
        }
    }
    return false; 
}