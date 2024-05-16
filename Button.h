#ifndef BUTTON_H
#define BUTTON_H

#include <wiringPi.h>

class Button {
public:
    Button(int ledPin, int sw1Pin); 
    void update();
    bool isPressed() const;

private:
    int ledPin;
    int sw1Pin;
};

#endif
