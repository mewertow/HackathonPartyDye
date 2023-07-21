#pragma once

#include "../libraries/DallasTemperature-3.9.0/DallasTemperature.h"
#include "../libraries/OneWire-2.3.7/OneWire.h"

class Thermistor
{
public:
    inline float getTemp() const
    {
        return current_temp;
    }
    // float setTemp(int target_temp);
};

extern Thermistor thermistor;
