#ifndef FES_H
#define FES_H

#define PWM_LOW_THRESHOLD 4
#define DEFAULT_INTENSITY 1
#define FES_THRESHOLD 2000
#define FES_DEFAULT_TIME_ON 121
#define FES_MINIMUM_TIME_ON 120
#define DELAY_AFTER_FES 4000

class Fes
{
private:
    float threshold; //Initial Threshold - to do not trigger
    int intensity; //Initial PWM - FES intensity
    bool is_on; 
    int on_time; //initial FES time (1s)
public:
    Fes(int output_a, int output_b);
    ~Fes();

    void increasePwm(int increment);
    void decreasePwm(int decrement);
    void stopPwm();

    void increaseDuration(int increment);
    void decreaseDuration(int decrement);
    void generatePositiveSignal();
    void generateZeroSignal();
    void generateNegativeSignal();
    void on(float frequency);
    void rise();
    void decay();
    void run();
    bool isOn();
};

#endif