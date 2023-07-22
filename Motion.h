// #pragma once
// #include "Configuration.h"

// // if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
// // // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
// // Serial.println("Could not find Motor Shield. Check wiring.");
// // while (1);
// // // }
// // Serial.println("Motor Shield found.");

// void home(Adafruit_StepperMotor *myMotor);
// void raise(Adafruit_StepperMotor *myMotor);
// int steps_calc(float distance);

// static int raise_height = 300; // target in mm
// static int steps_per_cycle = 200;
// static float cycle_travel = 2.3; // mm in 200 steps