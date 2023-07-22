#include "impeller.h"
#include <Arduino.h>
#include "../pins.h"
#include <Stepper.h>

Impeller impeller;

// void Impeller::setStepDelay(float desired_speed) // input in RPM
// {
//     unsigned long time_conversion = 60L * 1000L * 1000L / steps_per_revolution;
//     step_delay = (unsigned long)(time_conversion / desired_speed) / 1000; // returns delay in milliseconds
// }

void Impeller::init()
{
    pinMode(IMPELLER_STEP_PIN, OUTPUT);
    pinMode(IMPELLER_DIRECTION_PIN, OUTPUT);
    digitalWrite(IMPELLER_DIRECTION_PIN, HIGH);
    digitalWrite(IMPELLER_STEP_PIN, LOW);
}

void Impeller::spin()
{
    static unsigned long now = millis();
    if ((millis() - now) >= 0.5)
    {
        now = millis();
        digitalWrite(IMPELLER_STEP_PIN, HIGH);
    }
    digitalWrite(IMPELLER_STEP_PIN, LOW);
}

void Impeller::turnOff()
{
    digitalWrite(IMPELLER_STEP_PIN, LOW);
}