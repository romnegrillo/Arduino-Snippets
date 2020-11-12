// UART Communication for Receiving Checking GPS Data.
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

}

void loop() 
{  
  while(ss.available())
  {
    Serial.print(char(ss.read()));
  }
}
