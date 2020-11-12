const int ledPin=2;
const int buttonPin=3;
int buttonState=0;
int ledState=0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  attachInterrupt(1, buttonChange, RISING);
}

void loop()
{
  if(state!=0)
  {
    digitalWrite(ledPin, !ledState)
    state=0;
  }
}

void buttonChange()
{
  state++;
}

