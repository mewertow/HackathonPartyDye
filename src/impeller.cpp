#include "impeller.h"
#include <Arduino.h>
#include "../pins.h"
#include <Stepper.h>

Impeller impeller;
// Stepper stepper(200, A15, A14, A13, A12);

void Impeller::setStepDelay(float desired_speed) // input in RPM
{
    unsigned long time_conversion = 60L * 1000L * 1000L / steps_per_revolution;
    step_delay = (unsigned long)(time_conversion / desired_speed) / 1000; // returns delay in milliseconds
}

void Impeller::init()
{
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIRECTION_PIN, OUTPUT);
    digitalWrite(DIRECTION_PIN, HIGH);
}

void Impeller::spin()
{
    // delay(1000);
    static unsigned long now = millis();
    if ((millis() - now) >= 0.5)
    {
        now = millis();
        digitalWrite(STEP_PIN, HIGH);
    }
    digitalWrite(STEP_PIN, LOW);
}