#pragma once

class LED
{
    void turnOn(int led_pin);
    void turnOff(int led_pin);
};

extern LED led;