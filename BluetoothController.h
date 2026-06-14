#ifndef BLUETOOTH_CONTROLLER_H
#define BLUETOOTH_CONTROLLER_H

#include <SoftwareSerial.h>

// ====================================
// # BLUETOOTH CONTROLLER
// ====================================

class BluetoothController
{
  private:

    SoftwareSerial BT;

  public:

    // ====================================
    // # CONSTRUCTOR
    // ====================================

    BluetoothController(
      int rxPin,
      int txPin);

    // ====================================
    // # METHODS
    // ====================================

    void begin(long baudRate);

    bool available();

    char readCommand();
};

#endif