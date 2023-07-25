#include "fan.h"
#include "../pins.h"

Fan fan;

void Fan::turnOn()
{
    digitalWrite(FAN_PIN, HIGH);
}

void Fan::turnOff()
{
    digitalWrite(FAN_PIN, LOW);
}