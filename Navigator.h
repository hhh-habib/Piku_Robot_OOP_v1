#ifndef NAVIGATOR_H
#define NAVIGATOR_H

// ====================================
// # INCLUDE MODULES
// ====================================

#include "DistanceSensor.h"
#include "ServoScanner.h"

// ====================================
// # NAVIGATOR
// ====================================

class Navigator
{
  private:

    DistanceSensor* sensor;

    ServoScanner* scanner;

  public:

    // ====================================
    // # CONSTRUCTOR
    // ====================================

    Navigator(
      DistanceSensor* sensorPtr,
      ServoScanner* scannerPtr);

    // ====================================
    // # METHODS
    // ====================================

    float scanLeft();

    float scanCenter();

    float scanRight();
};

#endif