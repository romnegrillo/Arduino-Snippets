#include<EEPROM.h>

String writeEEProm="Rom Negrillo";
String readEEProm="";

void setup() 
{
  Serial.begin(9600);

  Serial.println("Writing in EEPROM...");
  
  for (int i=0; i<writeEEProm.length(); i++)
  {
    EEPROM.write(i, writeEEProm[i]);
  }

  for (int i=0; i<writeEEProm.length(); i++)
  {
    byte myByte= EEPROM.read(i);
    readEEProm+=myByte;
  } 

  Serial.print("Read from EEPROM: ");
  Serial.println(readEEProm);
}

void loop()
{
  
}
