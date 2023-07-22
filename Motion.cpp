// #include "Configuration.h"
// #include "motion.h"

// void home(Adafruit_StepperMotor *myMotor) {
//     while(digitalRead(11)) {
//         myMotor->step(1, BACKWARD, SINGLE);
//     }
// }

// void raise(Adafruit_StepperMotor *myMotor) {
//     int steps = steps_calc(raise_height);
//     myMotor->step(steps, FORWARD, SINGLE);
// }

// int steps_calc(float distance) {
//     int steps = (distance / cycle_travel) * steps_per_cycle;
//     return steps;
// }
