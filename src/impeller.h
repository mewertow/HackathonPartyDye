// int step_count = 0;

#pragma once
#include <Arduino.h>

class Impeller
{
public:
    void init();
    void spin(float ramp_delay);
    void ramp();
    // void heat();
    void turnOff();
    // void setStepDelay(float desired_speed); // in RPM
    // float step_delay;
    // int steps_per_revolution = 200;
    // float speed = 100; // RPM

    // float ramp_delay;
};

extern Impeller impeller;