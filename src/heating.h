#pragma once

#include <Arduino.h>
#include "../Configuration.h"
#include "../pins.h"

class Thermistor
{
public:
    void measure();
    inline float getThermistorTemperature() const
    {
        return current_thermistor_temperature;
    }

private:
    volatile float current_thermistor_temperature = MIN_TEMPERATURE;
    struct
    {
        const float beta = 3435.0;
        const float room_temperature = 298.0;
        const float resistance_roomtemp = 10000.0;
        const float resistance_bias = 10000.0;
    } m_thermistor;
};

extern Thermistor thermistor;
