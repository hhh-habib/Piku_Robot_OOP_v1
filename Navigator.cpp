// ====================================
// # INCLUDE MODULES
// ====================================

#include "Navigator.h"
#include <Arduino.h>
// ====================================
// # CONSTRUCTOR
// ====================================

Navigator::Navigator(
  DistanceSensor* sensorPtr,
  ServoScanner* scannerPtr)
{
  sensor = sensorPtr;

  scanner = scannerPtr;
}

// ====================================
// # SCAN LEFT
// ====================================

float Navigator::scanLeft()
{
  scanner->lookLeft();

  delay(700);

  return sensor->getDistance();
}

// ====================================
// # SCAN CENTER
// ====================================

float Navigator::scanCenter()
{
  scanner->lookCenter();

  delay(700);

  return sensor->getDistance();
}

// ====================================
// # SCAN RIGHT
// ====================================

float Navigator::scanRight()
{
  scanner->lookRight();

  delay(700);

  return sensor->getDistance();
}