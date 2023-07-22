#include "fan.h"
#include "../pins.h"

Fan fan;

void Fan::turnOn()
{
    analogWrite(FAN_PIN, HIGH);
}

void Fan::turnOff()
{
    analogWrite(FAN_PIN, LOW);
}