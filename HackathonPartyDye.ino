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
    // pinMode(RED_LED, OUTPUT);
    // pinMode(BLUE_LED, OUTPUT);
    // pinMode(GREEN_LED, OUTPUT);
    // pinMode(FAN_PIN, OUTPUT);

    // fan.turnOff();
    // heater.turnOff();
    // led.turnOff(HEAT_LED);
    // led.turnOff(DONE_LED);
    // led.turnOff(START_DYE_LED);

    // // Motors off
    impeller.init();
    // platform.init();

    impeller.ramp();
    // delay(5000);

    // platform.home();
    // platform.raise(RAISE_DISTANCE);
}

void loop()
{
    // impeller.ramp();
    // delay(5000);
    impeller.spin();
    // platform.raise(RAISE_DISTANCE);
    // thermistor.measure();
    // Serial.println(thermistor.getThermistorTemperature());
    // delay(1000);
    // if (digitalRead(PWR_BUTTON))
    // {
    //     led.turnOff(DONE_LED);
    //     led.turnOn(START_DYE_LED);
    // dye.prepBath();
    // dye.dyeProcedure(DYE_TIME);
    // dye.dyeCleanUp(COOL_TIME);
    //     led.turnOff(START_DYE_LED);
    // }
    // platform.home();
    // platform.raise(RAISE_DISTANCE);
    // impeller.spin();
    // digitalWrite(HEATER_PIN, HIGH);
    // delay(1000);
    // digitalWrite(HEATER_PIN, LOW);
    // delay(1000);
    //
    // fan.turnOn();
    // delay(2000);
    // fan.turnOff();
    // delay(2000);
    // digitalWrite(RED_LED, HIGH);
    // delay(2000);
    // digitalWrite(RED_LED, LOW);
    // digitalWrite(BLUE_LED, HIGH);
    // delay(2000);
    // digitalWrite(BLUE_LED, LOW);
    // delay(5000);
    // digitalWrite(BLUE_LED, 0);
    // digitalWrite(GREEN_LED, HIGH);
    // delay(2000);
    // digitalWrite(GREEN_LED, LOW);
    // delay(5000);
    // analogWrite(GREEN_LED, 0);
}
