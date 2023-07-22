#include "led.h"
#include "pins.h"
#include <Arduino.h>

LED led;

void LED::turnOn(int led_pin)
{
    digitalWrite(led_pin, HIGH);
}

void LED::turnOff(int led_pin)
{
    digitalWrite(led_pin, LOW);
}
