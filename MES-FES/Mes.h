#ifndef MES_H
#define MES_H

#include "MesFilter.h"
#include "Fes.h"
#define IMPEDANCE_THRESHOLD 10
#define DEFAULT_DIFFICULTY 16
#define MINIMUM_DIFFICULTY 1
#define TRIGGER_MINIMUM_THRESHOLD 3
#define MES_GAIN 100

class Mes
{
private:
    MesFilter* filter;
    int pin;
    float last_value; 
    
    static float filtered_value[50];
    static float mes[5];
    static float values[2];

    static float gain;
    static float difficulty;

    static float threshold;

    static float mes_a[2];
    static float mes_b[2];
    float voltage;
public:
    Mes(int pin);
    ~Mes();
    void increaseDifficulty(int increment);
    void decreaseDifficulty(int decrement);
    bool is_trigger(Fes* fes, int tilt);
    void updateMovingThreshold();
    bool impedanceTooLow();
    float readSensor();
    void acquire();
    void print();
};

#endif