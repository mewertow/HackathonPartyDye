#include "heating.h"
#include "thermistor.h"
#include <Arduino.h>
#include "../led.h"
Heater heater;

void Heater::heat()
{
    thermistor.measure();
    static unsigned long now = millis();
    if ((millis() - now) > 60000)
    {
        now = millis();
        if (thermistor.getThermistorTemperature() > 60.0)
        {
            digitalWrite(HEATER_PIN, LOW);
            led.turnOff(RED_LED);
            isHeated = true;
        }
        else if (thermistor.getThermistorTemperature() < 55.0)
        {
            digitalWrite(HEATER_PIN, HIGH);
            led.turnOn(RED_LED);
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
