#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

class MotorDriver
{
  private:

// ====================================
// # MOTOR BALANCE
// ====================================

int leftOffset = 0;

// ====================================
// # DEFAULT MANUAL SPEED
// ====================================

int speed = 80;

    int AIN1;
    int AIN2;
    int BIN1;
    int BIN2;

  public:

    // ====================================
    // # SPEED CONTROL
    // ====================================

    void setSpeed(int newSpeed);

    MotorDriver(
      int ain1,
      int ain2,
      int bin1,
      int bin2);

    void begin();

    void forward();

    void backward();

    void leftPivot();

    void rightPivot();

    void stop();
};

#endif