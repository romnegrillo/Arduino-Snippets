#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(53, 52);
String inText;
String phoneNumber = "+639171709038";

void setup()
{
  Serial.begin(9600);
  initGSM();
  sendSMS("Testing");
}

void loop()
{
  receiveSMS();
  //sendSMS("Testing");

  delay(1000);
}

void initGSM()
{
  gsmSerial.begin(9600);

  while (!gsmSerial.available())
  {
    gsmSerial.println("AT");
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected!");
  gsmSerial.println("AT+CMGF=1");
  updateSerial();

  gsmSerial.println("AT + CMGS = \"" + phoneNumber + "\"");
  updateSerial();

  gsmSerial.print("GSM initialized.");
  updateSerial();

  gsmSerial.write((char)26);
  updateSerial();


  // Receive mode.
  gsmSerial.print("AT+CNMI=1,2,0,0,0\r");
  delay(1000);
}

void sendSMS(String message)
{
  gsmSerial.println("AT+CMGF=1");
  updateSerial();

  gsmSerial.println("AT + CMGS = \"" + phoneNumber + "\"");
  updateSerial();

  gsmSerial.print(message);
  updateSerial();

  gsmSerial.write((char)26);
  updateSerial();

  // Receive mode.
  gsmSerial.print("AT+CNMI=1,2,0,0,0\r");
  updateSerial();
}

void receiveSMS()
{
  if (gsmSerial.available() > 0)
  {
    //Get the character from the cellular serial port
    inText = gsmSerial.readString();

    Serial.println("Received Text: ");
    Serial.println(inText);

    inText = "";
  }
}

void updateSerial()
{
  delay(500);

  while (Serial.available())
  {
    gsmSerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (gsmSerial.available())
  {
    Serial.write(gsmSerial.read());//Forward what Software Serial received to Serial Port
  }
}
