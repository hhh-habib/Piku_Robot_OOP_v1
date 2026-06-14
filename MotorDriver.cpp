#include "MotorDriver.h"

#include <Arduino.h>


MotorDriver::MotorDriver(
  int ain1,
  int ain2,
  int bin1,
  int bin2)
{
  AIN1 = ain1;
  AIN2 = ain2;

  BIN1 = bin1;
  BIN2 = bin2;
}

void MotorDriver::begin()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

// ==============================
// # FORWARD
// ==============================

void MotorDriver::forward()
{
    analogWrite(AIN1, 150);
    analogWrite(AIN2, 0);

    analogWrite(BIN1, 150);
    analogWrite(BIN2, 0);
}

void MotorDriver::backward()
{

    analogWrite(AIN1, 0);
    analogWrite(AIN2, speed + 10);

    analogWrite(BIN1, 0);
    analogWrite(BIN2, speed -5);
} 

void MotorDriver::leftPivot()
{
  analogWrite(AIN1, speed + 30);
  analogWrite(AIN2, 0);

  analogWrite(BIN1, 0);
  analogWrite(BIN2, speed + 25);
}

void MotorDriver::rightPivot()
{
  analogWrite(AIN1, 0);
  analogWrite(AIN2, speed + 30);

  analogWrite(BIN1, 150);
  analogWrite(BIN2, 0);
}

void MotorDriver::stop()
{
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 0);

  analogWrite(BIN1, 0);
  analogWrite(BIN2, 0);
}

// ====================================
// # SET SPEED
// ====================================

void MotorDriver::setSpeed(int newSpeed)
{
    speed = constrain(newSpeed, 0, 255);

    Serial.print("Motor Speed = ");
    Serial.println(speed);
}