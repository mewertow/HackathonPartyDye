#include "src/thermistor.h"
#include "src/heating.h"
#include "src/impeller.h"
#include "pins.h"
#include "led.h"
#include "src/fan.h"
#include "dye.h"
#include <Arduino.h>
#include "Configuration.h"
#include "platform.h"

int raise_distance = 10;
int dye_time = 0.5;  // in minutes
int cool_time = 0.5; // in minutes

void setup()
{
    Serial.begin(9600);
    Serial.println("PARTY TIME");

    fan.turnOff();
    heater.turnOff();
    led.turnOff(HEAT_LED);
    led.turnOff(DONE_LED);
    led.turnOff(START_DYE_LED);

    // Motors off
    impeller.init();
    platform.init();

    platform.home();
    platform.raise(RAISE_DISTANCE);
}

void loop()
{
    if (digitalRead(PWR_BUTTON))
    {
        led.turnOff(DONE_LED);
        led.turnOn(START_DYE_LED);
        dye.prepBath();
        dye.dyeProcedure(DYE_TIME);
        dye.dyeCleanUp(COOL_TIME);
        led.turnOff(START_DYE_LED);
    }
}
