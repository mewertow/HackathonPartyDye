#pragma once

#include <Arduino.h>
#include "../pins.h"
#include "thermistor.h"

class Heater
{
public:
    void heat();

    inline void getHeaterStatus()
    {
        if (digitalRead(HEATER_PIN) == HIGH)
        {
            Serial.println("HEATER ON");
            Serial.println(thermistor.getThermistorTemperature());
        }
        else
        {
            Serial.println("HEATER OFF");
            Serial.println(thermistor.getThermistorTemperature());
        }
    }
};

extern Heater heater;