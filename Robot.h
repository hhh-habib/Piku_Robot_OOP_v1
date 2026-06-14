#ifndef ROBOT_H
#define ROBOT_H

// ====================================
// # INCLUDE MODULES
// ====================================

#include "MotorDriver.h"
#include "DistanceSensor.h"
#include "ServoScanner.h"
#include "BluetoothController.h"
#include "Navigator.h"

// ====================================
// # ROBOT CLASS
// ====================================

class Robot
{
  private:

    // ====================================
    // # MODULES
    // ====================================

    MotorDriver motor;

    DistanceSensor sensor;

    ServoScanner scanner;

    BluetoothController bluetooth;

    Navigator navigator;

    // ====================================
    // # STATE
    // ====================================

    bool autoMode;

    int motorSpeed;

  public:

    // ====================================
    // # SPEED CONTROL
    // ====================================

    void setSpeedFromCommand(char cmd);

    // ====================================
    // # AUTONOMOUS
    // ====================================

    void runAutonomous();

    void executeCommand(char cmd);

    // ====================================
    // # CONSTRUCTOR
    // ====================================
    void processBluetooth();
    Robot();

    // ====================================
    // # METHODS
    // ====================================

    void begin();

    void update();
};

#endif