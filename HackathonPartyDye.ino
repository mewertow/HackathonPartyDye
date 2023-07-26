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

void setup()
{
    Serial.begin(9600);
    Serial.println("PARTY TIME");

    // TODO: create init() functions for LEDs, limit swich, and heater
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(FAN_PIN, OUTPUT);
    pinMode(LIMIT_PIN, INPUT);
    pinMode(HEATER_PIN, OUTPUT);

    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);

    // fan.turnOff();
    heater.turnOff();

    // // Motors off
    impeller.init();
    platform.init();

    dye.dyeReset();
    dye.prepBath();

    // impeller.ramp();
    // impeller.spin();
}

void loop()
{
    digitalWrite(HEATER_PIN, LOW);
    // impeller.spin();
    fan.turnOn();
    thermistor.measure();

    // dye.prepBath();
    // dye.dyeProcedure(DYE_TIME);
    // dye.dyeCleanUp(COOL_TIME);
}
