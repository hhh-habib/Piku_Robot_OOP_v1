#include "ServoScanner.h"

// ====================================
// # CONSTRUCTOR
// ====================================

ServoScanner::ServoScanner(
  int pin,
  int left,
  int center,
  int right)
{
  servoPin = pin;

  leftAngle = left;
  centerAngle = center;
  rightAngle = right;
}

// ====================================
// # BEGIN
// ====================================

void ServoScanner::begin()
{
  scanner.attach(servoPin);

  lookCenter();
}

// ====================================
// # LOOK LEFT
// ====================================

void ServoScanner::lookLeft()
{
  scanner.write(leftAngle);
}

// ====================================
// # LOOK CENTER
// ====================================

void ServoScanner::lookCenter()
{
  scanner.write(centerAngle);
}

// ====================================
// # LOOK RIGHT
// ====================================

void ServoScanner::lookRight()
{
  scanner.write(rightAngle);
}