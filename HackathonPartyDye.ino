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

    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(HEATER_PIN, LOW);

    // fan.turnOff();
    heater.turnOff();

    // // Motors off
    impeller.init();
    platform.init();

    // Prep bath and platform
    dye.dyeReset();
    dye.prepBath();
}

void loop()
{
    impeller.spin(1.25);
    dye.heat();

    static unsigned long now = millis();
    while (millis() - now < DYE_TIME * 60 * 1000)
    {
        dye.dyeProcedure(DYE_TIME);
    }

    dye.dyeCleanUp(COOL_TIME);
    return;
}
