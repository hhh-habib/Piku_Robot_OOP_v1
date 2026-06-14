#include "Robot.h"
#include <Arduino.h>

// ====================================
// # CONSTRUCTOR
// ====================================

Robot::Robot()

  :

  motor(
    5,
    6,
    11,
    3),

  sensor(
    12,
    13),

  scanner(
    4,
    180,
    90,
    0),

  bluetooth(
    7,
    8),

  navigator(
    &sensor,
    &scanner)

{
  autoMode = false;

  motorSpeed = 200;
}

// ====================================
// # BEGIN
// ====================================

void Robot::begin()
{
  Serial.begin(9600);

  motor.begin();

  sensor.begin();

  scanner.begin();

  bluetooth.begin(9600);

  Serial.println("ROBOT READY");
}

// ====================================
// # UPDATE
// ====================================

void Robot::update()
{
  processBluetooth();

  if(autoMode)
  {
    runAutonomous();
  }
}
  // ====================================
// # EXECUTE COMMAND
// ====================================

void Robot::executeCommand(char cmd)
{
    if(cmd >= '1' && cmd <= '6')
    {
        setSpeedFromCommand(cmd);

        return;
    } 
    switch(cmd)
    {
    // ====================================
    // # FORWARD
    // ====================================

    case 'F':

      autoMode = true;

      Serial.println("AUTO MODE");

      break;

    // ====================================
    // # BACKWARD
    // ====================================

    case 'B':

      autoMode = false;

      motor.backward();

      break;

    case 'L':

      autoMode = false;

      motor.leftPivot();

      break;

    case 'R':

      autoMode = false;

      motor.rightPivot();

      break;

    case 'S':

      autoMode = false;

      motor.stop();

      break;

    case 'T':

      autoMode = false;

      motor.forward();

      Serial.println("TEST FORWARD");
      break;
  }

}

// ====================================
// # SPEED CONTROL
// ====================================

void Robot::setSpeedFromCommand(char cmd)
{
    switch(cmd)
    {
        case '1':

            motor.setSpeed(80);

            Serial.println("SPEED 80");

            break;

        case '2':

            motor.setSpeed(125);

            Serial.println("SPEED 125");

            break;

        case '3':

            motor.setSpeed(170);

            Serial.println("SPEED 170");

            break;

        case '4':

            motor.setSpeed(190);

            Serial.println("SPEED 190");

            break;

        case '5':

            motor.setSpeed(225);

            Serial.println("SPEED 225");

            break;
    }
}
// ====================================
// # BLUETOOTH PROCESSOR
// ====================================

void Robot::processBluetooth()
{
  if(bluetooth.available())
  {
    char cmd =
      bluetooth.readCommand();

    executeCommand(cmd);
  }
}

// ====================================
// # AUTONOMOUS MODE
// ====================================

void Robot::runAutonomous()
{
  float frontDistance =
    navigator.scanCenter();

  Serial.print("Front = ");
  Serial.println(frontDistance);

  if(frontDistance > 20)
  {
    motor.forward();

    return;
  }

  Serial.println("OBSTACLE DETECTED");

  motor.stop();

  float leftDistance =
    navigator.scanLeft();

  float rightDistance =
    navigator.scanRight();

  Serial.print("Left = ");
  Serial.println(leftDistance);

  Serial.print("Right = ");
  Serial.println(rightDistance);

  if(leftDistance > rightDistance)
  {
    Serial.println("TURN LEFT");

    motor.leftPivot();

    delay(700);
  }
  else
  {
    Serial.println("TURN RIGHT");

    motor.rightPivot();

    delay(700);
  }

  motor.stop();
}