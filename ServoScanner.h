#ifndef SERVO_SCANNER_H
#define SERVO_SCANNER_H

#include <Servo.h>

// ====================================
// # SERVO SCANNER CLASS
// ====================================

class ServoScanner
{
  private:

    Servo scanner;

    int servoPin;

    int leftAngle;
    int centerAngle;
    int rightAngle;

  public:

    // ====================================
    // # CONSTRUCTOR
    // ====================================

    ServoScanner(
      int pin,
      int left,
      int center,
      int right);

    // ====================================
    // # METHODS
    // ====================================

    void begin();

    void lookLeft();

    void lookCenter();

    void lookRight();
};

#endif