#include "heating.h"
#include "thermistor.h"
#include <Arduino.h>

Heater heater;

void Heater::heat()
{
    static unsigned long now = millis();
    if ((millis() - now) > 60000)
    {
        now = millis();
        if (thermistor.getThermistorTemperature() > 90.0)
        {
            digitalWrite(HEATER_PIN, LOW);
            isHeated = true;
        }
        else if (thermistor.getThermistorTemperature() < 85.0)
        {
            digitalWrite(HEATER_PIN, HIGH);
            isHeated = false;
        }
        else if (isnan(thermistor.getThermistorTemperature()))
        {
            digitalWrite(HEATER_PIN, LOW);
            Serial.println("ERROR");
            Serial.println(thermistor.getThermistorTemperature());
        }
    }
}

void Heater::turnOff()
{
    digitalWrite(HEATER_PIN, LOW);
}
