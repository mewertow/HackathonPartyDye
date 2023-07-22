#pragma once
#include <Arduino.h>

class Fan
{
public:
    void turnOn();
    void turnOff();
};

extern Fan fan;