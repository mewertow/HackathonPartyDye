#include "impeller.h"
#include <Arduino.h>
#include "../pins.h"
#include <Stepper.h>

Impeller impeller;
Stepper stepper(200, A15, A14, A13, A14);

void Impeller::setStepDelay(float desired_speed) // input in RPM
{
    unsigned long time_conversion = 60L * 1000L * 1000L / steps_per_revolution;
    step_delay = (unsigned long)(time_conversion / desired_speed); // returns delay in microseconds
}

void Impeller::init()
{
    Serial.println("motor initialized");
    setStepDelay(50);
    Serial.println(step_delay);
}

void Impeller::spin()
{
    static unsigned long now = millis();
    if ((millis() - now) >= 100)
    {
        now = millis();
        stepper.step(speed);
        // speed = -speed;
        Serial.println("motor on");
    }
}