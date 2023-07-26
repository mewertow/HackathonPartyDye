#include "dye.h"
#include "src/heating.h"
#include "src/thermistor.h"
#include "src/fan.h"
#include "led.h"
#include "pins.h"
#include "Configuration.h"
#include "platform.h"
#include "src/impeller.h"

Dye dye;

void Dye::dyeMonitor()
{
    static unsigned long now = millis();
    if ((millis() - now) >= 5000)
    {
        Serial.println(thermistor.getThermistorTemperature());
    }
}

// TODO: accept raise distance
void Dye::dyeReset()
{
    platform.home();
    platform.raise(RAISE_DISTANCE);
    delay(10000);
}

bool Dye::prepBath()
{
    platform.home();
    impeller.ramp();
}

void Dye::heat()
{
    while (!heater.isHeated)
    {
        heater.heat();
        impeller.spin(1.25);
        // dyeMonitor();
    }
}

void Dye::dyeProcedure(int dye_time)
{
    heater.heat();
    impeller.spin(1.25);
    // dyeMonitor();
    // return;
}

void Dye::dyeCleanUp(int cool_time)
{
    heater.turnOff();
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(HEATER_PIN, HIGH);
    impeller.turnOff();
    platform.raise(RAISE_DISTANCE); // static unsigned long now = millis();
    // led.turnOn(DONE_LED);
}
