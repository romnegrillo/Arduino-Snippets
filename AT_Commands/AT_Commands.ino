// UART Communication for AT Commands.
// Pinout:
// Arduino to module.
// TX -> RX
// RX -> TX
// Gnd -> Gnd
// Power supply maybe from the same source 
// or not depending on the module.

#include<SoftwareSerial.h>

SoftwareSerial ss(2,3);


void setup() 
{
  Serial.begin(9600);
  ss.begin(9600);

  Serial.println("Begin sending AT Commands.");
}

void loop() 
{
  while(Serial.available())
  {
    ss.write(Serial.read());
  }
  
  while(ss.available())
  {
    Serial.write(ss.read());
  }
}
