//Proj_MES-FES_Interface - Version 1.1 arduino UNO/Nano 24 Abr 2023 using bitalino sensor and tilt sensor
#include <Arduino.h>
#include <math.h>
#include <filters.h> // available in: https://github.com/MartinBloedorn/libFilter

#include "Led.h"
#include "Mes.h"
#include "Fes.h"

#define PIN_RED_LED 6
#define PIN_TILT 12
#define PIN_MES A0
#define FES_OUTPUT_A 9
#define FES_OUTPUT_B 10
#define PWM_INCREMENT 125
#define DURATION_INCREMENT 120
#define DIFFICULTY_INCREMENT 1

Led redLed(PIN_RED_LED);
Fes fes(FES_OUTPUT_A, FES_OUTPUT_B);
Mes mes(PIN_MES);

int tilt = 12; // tilt sensor - adjust the sensitivity in embedded potentiometer 
char bluetooth_input; 

void setup()
{
    //MValue = analogRead(A0); //MES
    pinMode(PIN_TILT, INPUT);    
    redLed.blink(3, 1000);
    Serial.begin(9600); //Initialize Serial Monitor
}

void bluetoothHandler() {
    switch (bluetooth_input)
    {
    case 'v':
        fes.increasePwm(PWM_INCREMENT);
        break;
    case 'c':
        fes.decreasePwm(PWM_INCREMENT);
        break;
    case 'x':
        fes.stopPwm();
        break;
    case 'd':
        fes.increaseDuration(DURATION_INCREMENT);
        break;
    case 's':
        fes.decreaseDuration(DURATION_INCREMENT);
        break;
    case 'g':
        mes.increaseDifficulty(DIFFICULTY_INCREMENT);
        break;
    case 'f':
        mes.decreaseDifficulty(DIFFICULTY_INCREMENT);
        break;
    
    default:
        bluetooth_input = '\0';
        break;
    }
    if(bluetooth_input != '\0') {
        redLed.blink();
    }
    bluetooth_input = '\0';
}

char readBluetooth() {
    bluetooth_input = Serial.available() ? Serial.read() : '\0';
    return bluetooth_input;
}



void readTilt() {
    tilt = digitalRead(PIN_TILT);
}

void loop() {
    readBluetooth();

    mes.acquire();
    readTilt();
    mes.updateMovingThreshold();
    if (mes.impedanceTooLow()) {
        redLed.blink();
    }
    mes.print();

    if(mes.is_trigger(&fes, tilt))
        fes.run();

    if (!fes.isOn())
        bluetoothHandler();    
}