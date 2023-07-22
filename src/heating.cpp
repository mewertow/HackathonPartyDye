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
        if (thermistor.getThermistorTemperature() > 60.0)
        {
            digitalWrite(HEATER_PIN, LOW);
            Serial.println("HEATER OFF");
        }
        else if (thermistor.getThermistorTemperature() < 30.0)
        {
            digitalWrite(HEATER_PIN, HIGH);
            Serial.println("HEATER ON");
        }
        else if (isnan(thermistor.getThermistorTemperature()))
        {
            digitalWrite(HEATER_PIN, LOW);
            Serial.println("ERROR");
            Serial.println(thermistor.getThermistorTemperature());
        }
    }
}