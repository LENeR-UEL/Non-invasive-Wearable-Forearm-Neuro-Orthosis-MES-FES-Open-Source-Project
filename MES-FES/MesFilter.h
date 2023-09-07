#ifndef MES_FILTER_H
#define MES_FILTER_H

#include <filters.h> // available in: https://github.com/MartinBloedorn/libFilter

#define LOW_CUTOFF_FREQUENCY 10.0
#define HIGH_CUTOFF_FREQUENCY 40.0
#define SAMPLING_TIME 0.01

class MesFilter
{
private:
    static const float f1 = LOW_CUTOFF_FREQUENCY;  //Cutoff frequency in Hz
    static const float f2 = HIGH_CUTOFF_FREQUENCY;  //Cutoff frequency in Hz

    static const float sampling_time = SAMPLING_TIME; //seconds.

    static const IIR::ORDER order = IIR::ORDER::OD3; // Butterworth - Oder (OD1 to OD4)
    static const IIR::TYPE typeHP = IIR::TYPE::HIGHPASS;

public:
    MesFilter();
    ~MesFilter();
    Filter* high_pass;
    Filter* low_pass;
};


#endif