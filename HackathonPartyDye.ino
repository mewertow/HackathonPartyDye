#include "src/thermistor.h"
"
#include "pins.h"
#include <Arduino.h>

    void
    setup()
{
    Serial.begin(9600);
    Serial.println("PARTY TIME");
}

void loop()
{
    thermistor.measure();
    Serial.println(thermistor.getThermistorTemperature());
    delay(1000);
}