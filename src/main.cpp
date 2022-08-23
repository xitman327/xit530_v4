#include <Arduino.h>
#include <ModbusMaster.h>
#include <uRTCLib.h>

#include "defines.h"
#include "iocontrol.h"

void preTransmission()
{
  digitalWrite(modbus_de, 1);
}

void postTransmission()
{
  digitalWrite(modbus_de, 0);
}
ModbusMaster modbus;

uRTCLib rtc(0x68);

void setup() {
  pinMode(modbus_de, OUTPUT);
  modbus.begin(1, modbus_bus);
  modbus.preTransmission(preTransmission);
  modbus.postTransmission(postTransmission);

  URTCLIB_WIRE.begin();
  rtc.disable32KOut();
}

void loop() {
  // put your main code here, to run repeatedly:
}