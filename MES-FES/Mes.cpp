#include "Mes.h"

float Mes::filtered_value[50] = {0};
float Mes::mes[5] = {0};
float Mes::values[2] = {0};
float Mes::gain = MES_GAIN;
float Mes::difficulty = DEFAULT_DIFFICULTY;
float Mes::threshold = 0;
float Mes::mes_a[2] = {0};
float Mes::mes_b[2] = {0};

Mes::Mes(int pin) {
    this->filter = new MesFilter;
    this->pin = pin;
    this->last_value = 0;
}

Mes::~Mes() {
}


void Mes::increaseDifficulty(int increment) {
    this->difficulty += increment;
}

void Mes::decreaseDifficulty(int decrement) {
    this->difficulty -= decrement;
    this->difficulty = (this->difficulty < MINIMUM_DIFFICULTY) ? MINIMUM_DIFFICULTY : this->difficulty;
}

bool Mes::is_trigger(Fes* fes, int tilt) {
    bool is_valid_low_threshold = this->threshold > TRIGGER_MINIMUM_THRESHOLD;
    bool is_in_interval = mes[1] >= this->threshold && mes[1] <= 60;

    return (is_in_interval && !fes->isOn() && is_valid_low_threshold && tilt == 0);
}

void Mes::updateMovingThreshold() {
    this->threshold = (1 + (this->difficulty / 100)) * this->mes[0]; 
}

bool Mes::impedanceTooLow() {
    return (values[0] > IMPEDANCE_THRESHOLD) ? true : false;
}

float average(float a, float b) {
    return (a + b)/2;
}

float Mes::readSensor() {
    for (int i = 0; i < 50; i++) {
        this->last_value = (analogRead(this->pin)); 
        this->voltage = ((3.3 / 1024.0) * this->last_value);

        this->filtered_value[i] = this->filter->low_pass->filterIn(this->voltage);
        this->filtered_value[i] = this->filter->high_pass->filterIn(this->filtered_value[i]);
        this->filtered_value[i] = abs(this->filtered_value[i]) * 100;

        delay(1);
    }

    float mes_average_10ms = 0;
    float sum_of_mes_averages = 0;

    for (int i = 0; i < 5; i++) {
        mes_average_10ms = 0;

        for (int j = 0; j < 10; j++) {
            mes_average_10ms += this->filtered_value[10*i + j];
        }

        mes_average_10ms /= 10;
        sum_of_mes_averages += mes_average_10ms;
    }
    
    return (this->gain * sum_of_mes_averages) / 10;
}

void Mes::acquire() {
    mes_a[0] = readSensor();
    mes_b[0] = readSensor();
    values[0] = average(mes_a[0], mes_b[0]);

    mes_a[1] = readSensor();
    mes_b[1] = readSensor();
    values[1] = average(mes_a[1], mes_b[1]);
}

void Mes::print() {
    Serial.print(this->threshold);
    Serial.print(" ");
    Serial.println(values[1]);
}