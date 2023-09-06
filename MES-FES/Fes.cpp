#include "Fes.h"
#include <Arduino.h>

Fes::Fes(int output_a, int output_b) {
    pinMode(output_a, OUTPUT); 
    pinMode(output_b, OUTPUT); 

    threshold = FES_THRESHOLD; 
    intensity = DEFAULT_INTENSITY; 
    is_on = false; 
    on_time = FES_DEFAULT_TIME_ON;
}

Fes::~Fes() {
}

void Fes::increasePwm(int increment) {
    intensity += increment;
}

void Fes::decreasePwm(int decrement) {
    intensity -= decrement;
    intensity = (intensity < PWM_LOW_THRESHOLD) ? 1 : intensity;
}

void Fes::stopPwm() {
    intensity = 1;
}

void Fes::increaseDuration(int increment) {
    on_time += increment;
}

void Fes::decreaseDuration(int decrement) {
    on_time -= decrement;
    on_time = (on_time < FES_MINIMUM_TIME_ON) ? 1 : on_time;
}

void Fes::generatePositiveSignal() {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
}

void Fes::generateZeroSignal() {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
}

void Fes::generateNegativeSignal() {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
}

void Fes::on(float frequency = 25000) { //keep frequency in 40Hz
    generatePositiveSignal();
    delayMicroseconds(intensity);
    generateZeroSignal();
    delayMicroseconds(10); //interpulse 10us off time
    generateNegativeSignal();
    delayMicroseconds(intensity);
    generateZeroSignal();
    delayMicroseconds((frequency - intensity) - (intensity));   
}

void Fes::rise() {
    for (float Tfreq = 50000; Tfreq >= 25000; Tfreq -= 937.5) {//Rise 20Hz to 40Hz 
        this->on(Tfreq) ;
    }
}

void Fes::decay() {
    for (float Tfreq = 25000; Tfreq >= 50000; Tfreq=Tfreq+937.5) { //Decay 40Hz to 20Hz
        this->on(Tfreq);
    } 
}

void Fes::run() {
    for (int i = 0; i < 8; i++) {
        Serial.write('p');//To App inventor
    }

    rise();
    this->is_on = true;

    int counter = 0;
    while (this->is_on && counter <= this->on_time) {
        this->on();
        counter++;
    }

    decay();
    this->is_on = false;
    
    for (int i = 0; i < 8; i++) {
        Serial.write('o');//To App inventor
    }

    delay(DELAY_AFTER_FES);
}

bool Fes::isOn()
{
    return this->is_on;
}
