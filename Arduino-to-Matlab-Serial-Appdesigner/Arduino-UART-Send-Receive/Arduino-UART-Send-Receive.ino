int ctr = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  String toSend = "Hello Rom!";
  toSend += ",";
  toSend += String(ctr);

  Serial.println(toSend);

  if (Serial.available())
  {
    String data = Serial.readStringUntil('\n');



    if (data == "OFF")
    {
      // Microcontroller used was inversed logic.

      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if (data == "ON")
    {
      // Microcontroller used was inversed logic.

      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  ctr++;
  delay(1000);
}
