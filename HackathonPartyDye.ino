#include "src/heating.h"
#include "libraries/DallasTemperature-3.9.0/DallasTemperature.h"
#include "libraries/OneWire-2.3.7/OneWire.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("PARTY TIME");
    sensors.begin;
}

void loop()
{
    thermistor.getTemp();
}