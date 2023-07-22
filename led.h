#pragma once

class LED
{
public:
    void turnOn(int led_pin);
    void turnOff(int led_pin);
};

extern LED led;