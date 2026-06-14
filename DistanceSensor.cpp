#include "DistanceSensor.h"

#include <Arduino.h>

DistanceSensor::DistanceSensor(
  int trig,
  int echo)
{
  trigPin = trig;
  echoPin = echo;
}

void DistanceSensor::begin()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float DistanceSensor::getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration =
    pulseIn(echoPin, HIGH, 30000);

  if(duration <= 0)
  {
    return 999;
  }

  return duration * 0.034 / 2;
}

