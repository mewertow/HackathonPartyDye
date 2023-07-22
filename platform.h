// int step_count = 0;

#pragma once
#include <Arduino.h>

class Platform
{
public:
    void init();
    // void spin();
    void home();
    void raise(float distance);
    int steps_calc(float distance); // in mm
    // void setStepDelay(float desired_speed); // in RPM
    // float step_delay;
    int steps_per_revolution = 200;
    // float speed = 100; // RPM
    int raise_steps;

    int raise_height = 300;
    float rev_travel = 2.3;
};

extern Platform platform;