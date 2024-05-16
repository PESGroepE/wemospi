#include "Button.h"

Button::Button(int ledPin, int sw1Pin) : ledPin(ledPin), sw1Pin(sw1Pin) {
    pinMode(ledPin, OUTPUT);
    pinMode(sw1Pin, INPUT);
    pullUpDnControl(sw1Pin, PUD_UP);
}

void Button::update() {
    if (isPressed()) {
        digitalWrite(ledPin, HIGH); 
    } else {
        digitalWrite(ledPin, LOW);
    }
}

bool Button::isPressed() const {
    return digitalRead(sw1Pin) == LOW;
}

