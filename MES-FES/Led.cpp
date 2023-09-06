#include "Led.h"
#include <Arduino.h>

Led::Led(int pin) {
    this->pin = pin;
    pinMode(this->pin, OUTPUT); 
}

Led::~Led() {
}

void Led::blink(int amount = 1, int interval = 50) {
    for (int i = 0; i < amount; i++) {
        this->on();
        delay(interval);
        this->off();
        delay(interval);
    }    
}

void Led::on() {
    digitalWrite(this->pin, HIGH);
}

void Led::off() {
    digitalWrite(this->pin, LOW);
}