#ifndef LED_H
#define LED_H

class Led
{
private:
    int pin;
public:
    Led(int pin);
    ~Led();
    void blink(int amount = 1, int interval = 50);
    void on();
    void off();  
};
#endif