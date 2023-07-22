// int step_count = 0;

#pragma once
#include <Arduino.h>

class Impeller
{
public:
    void init();
    void spin();
    void setStepDelay(float desired_speed); // in RPM
    float step_delay;
    int steps_per_revolution = 200;
    float speed = 100; // RPM
};

extern Impeller impeller;