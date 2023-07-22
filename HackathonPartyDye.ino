#include "src/thermistor.h"
#include "src/heating.h"
#include "src/impeller.h"
#include "pins.h"
#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    Serial.println("PARTY TIME");
    impeller.init();
}

void loop()
{
    // Serial.println(thermistor.getThermistorTemperature());
    thermistor.measure();
    heater.heat();
    impeller.spin();
    // timer.checkTime();
}