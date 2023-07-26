#include "impeller.h"
#include <Arduino.h>
#include "../pins.h"
#include <Stepper.h>

Impeller impeller;
volatile float ramp_delay = 3.0;

// Use RPM to calculate step_delay. RPM should go in Configuration.h
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

// TODO: pass final delay to spin() function
// We don't know why this works but it does
void Impeller::ramp()
{
    for (float i = 3.0; i > 1.0; i = i - 0.25)
    {
        for (int j = 0; j < 400; j++)
        {
            // Don't serial print in this loop
            digitalWrite(IMPELLER_STEP_PIN, HIGH);
            delay(i);
            digitalWrite(IMPELLER_STEP_PIN, LOW);
            delay(i);
            // Serial.println(i);
        }
        Serial.println(i);
    }

    // return ramp_delay;
}

void Impeller::spin(float ramp_delay)
{
    static unsigned long now = millis();
    if ((millis() - now) >= ramp_delay)
    {
        now = millis();
        digitalWrite(IMPELLER_STEP_PIN, HIGH);
    }
    else
    {
        digitalWrite(IMPELLER_STEP_PIN, LOW);
    }
}

void Impeller::turnOff()
{
    digitalWrite(IMPELLER_STEP_PIN, LOW);
}