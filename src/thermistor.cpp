#include "thermistor.h"
#include <Arduino.h>

Thermistor thermistor;
float calculateThermistorTemperature(int16_t temperature_raw,
                                     float resistance_rt,
                                     float resistance_b,
                                     float beta,
                                     float room_temperature)
{
    float resistance =
        resistance_b / (1023.0 / temperature_raw - 1.0);

    // temperature in Kelvin obtained from resistance by solving the Steinhart-Hart equation
    // (simplified), src: https://en.wikipedia.org/wiki/Thermistor#B_or_%CE%B2_parameter_equation
    float kelvin =
        (beta * room_temperature) / (beta + (room_temperature * log(resistance / resistance_rt)));

    // conversion from kelvin to celcius
    float celcius = kelvin - 273.0;
    return celcius;
}

void Thermistor::measure()
{
    int16_t temperature_thermistor_raw = analogRead(THERMISTOR_PIN);
    current_thermistor_temperature = calculateThermistorTemperature(temperature_thermistor_raw,
                                                                    m_thermistor.resistance_roomtemp,
                                                                    m_thermistor.resistance_bias,
                                                                    m_thermistor.beta,
                                                                    m_thermistor.room_temperature);
}