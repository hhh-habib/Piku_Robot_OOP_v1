#include "BluetoothController.h"

// ====================================
// # CONSTRUCTOR
// ====================================

BluetoothController::BluetoothController(
  int rxPin,
  int txPin)
  : BT(rxPin, txPin)
{
}

// ====================================
// # BEGIN
// ====================================

void BluetoothController::begin(
  long baudRate)
{
  BT.begin(baudRate);
}

// ====================================
// # AVAILABLE
// ====================================

bool BluetoothController::available()
{
  return BT.available();
}

// ====================================
// # READ COMMAND
// ====================================

char BluetoothController::readCommand()
{
  return BT.read();
}