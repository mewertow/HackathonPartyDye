// #include "src/heating.h"
// #include "libraries/DallasTemperature-3.9.0/DallasTemperature.h"
// #include "libraries/OneWire-2.3.7/OneWire.h"
#include "motion.h"
#include "Configuration.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

void setup()
{
  Serial.begin(9600);
    // Serial.println("PARTY TIME");
  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
  while (1);
  }
  Serial.println("Motor Shield found.");
  myMotor->setSpeed(10);  // 10 rpm

  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  digitalWrite(9, HIGH);
  pinMode(10, LOW);
}

void loop()
{
  // home(myMotor);
  raise(myMotor);
}
