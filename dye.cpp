#include "dye.h"
#include "src/heating.h"
#include "src/thermistor.h"
#include "src/fan.h"
#include "led.h"
#include "pins.h"
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

void Dye::prepBath()
{
    platform.home();
    impeller.spin();
    heater.heat();
    while (heater.isHeated == false)
        ;
    led.turnOn(HEAT_LED);
    return bath_ready = true;
}

void Dye::dyeProcedure(int dye_time)
{
    led.turnOn(START_DYE_LED);
    static unsigned long now = millis();
    while (millis() - now < dye_time * 60 * 1000)
    {
        heater.heat();
        dyeMonitor();
    }
    return;
}

void Dye::dyeCleanUp()
{
    heater.turnOff();
    platform.raise();
    impeller.turnOff();
    fan.turnOn();
    led.turnOn(DONE_LED);
}
