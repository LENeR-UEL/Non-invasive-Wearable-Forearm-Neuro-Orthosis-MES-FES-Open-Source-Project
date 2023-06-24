#include <Arduino.h>
#include <ArduinoJson.h>
#include <math.h>
#include <filters.h>  // available in: https://github.com/MartinBloedorn/libFilter

char blueToothVal;

// tilt sensor
const int tiltPin = 12;  // tilt sensor - adjust the sensitivity in embedded potentiometer

// MES
const int numSamples = 50;
float mesSamples[numSamples];

const float f2 = 40.0;                     // Cutoff frequency in Hz
const float f1 = 10.0;                     // Cutoff frequency in Hz
const float samplingTime = 0.01;           // Sampling time in seconds.
const IIR::ORDER order = IIR::ORDER::OD3;  // Butterworth - Order (OD1 to OD4)
const IIR::TYPE typeHP = IIR::TYPE::HIGHPASS;
Filter fHP(f1, samplingTime, order, typeHP);  // configure high pass filter (40 Hz)
Filter fLP(f2, samplingTime, order);          // configure low pass filter (10 Hz)

// FES
const float threshold = 2000;  // Initial Threshold - to do not trigger
int intensity = 1;             // Initial PWM - FES intensity
int flag = 0;
int cont = 1;
int timeOn = 121;        // Initial FES time (1s)
float riseTime = 50000;  // 20Hz - FES rise time

void setup() {
  pinMode(tiltPin, INPUT);
  pinMode(6, OUTPUT);  // LED red

  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);
  delay(1000);
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);
  delay(1000);
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);

  Serial.begin(9600);  // Initialize Serial Monitor

  // FES to H bridge
  pinMode(9, OUTPUT);   // FES_1
  pinMode(10, OUTPUT);  // FES_2
}

void readMES() {
  for (int i = 0; i < numSamples; i++) {
    float mValue = analogRead(A0);
    float voltage = (3.3 / 1024.0) * mValue;
    float filteredVal = fLP.filterIn(voltage);
    filteredVal = fHP.filterIn(filteredVal);
    filteredVal = abs(filteredVal);
    filteredVal *= 100;
    mesSamples[i] = filteredVal;
    delay(1);
  }
}

float calculateAverageMES() {
  float sum = 0;
  for (int i = 0; i < numSamples; i++) {
    sum += mesSamples[i];
  }
  return sum / numSamples;
}

void loop() {
  readMES();
  float averageMES = calculateAverageMES();

  // Do something with the average MES value

  delay(100);
}
