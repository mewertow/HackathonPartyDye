#include "platform.h"
#include <Arduino.h>
#include "pins.h"
#include <Stepper.h>

Platform platform;

// void Platform::setStepDelay(float desired_speed) // input in RPM
// {
//     unsigned long time_conversion = 60L * 1000L * 1000L / steps_per_revolution;
//     step_delay = (unsigned long)(time_conversion / desired_speed) / 1000; // returns delay in milliseconds
// }

void Platform::init()
{
    pinMode(PLATFORM_STEP_PIN, OUTPUT);
    pinMode(PLATFORM_DIRECTION_PIN, OUTPUT);
    pinMode(LIMIT_PIN, INPUT);
    digitalWrite(PLATFORM_DIRECTION_PIN, LOW);
    digitalWrite(PLATFORM_STEP_PIN, LOW);
}

void Platform::home()
{
    digitalWrite(PLATFORM_DIRECTION_PIN, LOW);
    while (digitalRead(LIMIT_PIN))
    {
        static unsigned long now = millis();
        if ((millis() - now) >= 0.025)
        {
            now = millis();
            digitalWrite(PLATFORM_STEP_PIN, HIGH);
        }
        else
        {
            digitalWrite(PLATFORM_STEP_PIN, LOW);
        }
    }
}

void Platform::raise(float distance)
{
    digitalWrite(PLATFORM_DIRECTION_PIN, HIGH);
    int raise_steps = steps_calc(distance);
    for (int i = 0; i < raise_steps; i++)
    {
        digitalWrite(PLATFORM_STEP_PIN, HIGH);
        delay(1);
        digitalWrite(PLATFORM_STEP_PIN, LOW);
        delay(1);
        // Serial.println(raise_steps);
    }
}

int Platform::steps_calc(float distance)
{
    int steps = (distance / rev_travel) * steps_per_revolution;
    return steps;
}