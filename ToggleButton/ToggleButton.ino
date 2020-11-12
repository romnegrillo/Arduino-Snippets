//OnOffButton

const int ledPin=13;
const int buttonPin=2;

int lastButtonState=0;
int currButtonState=0;
int ledState=0;

unsigned long startTime=0;
int debounceTime=50;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  //Read button state.
  int buttonReading=digitalRead(buttonPin);

  //Check of there is a transition.
  if(buttonReading!=lastButtonState)
  {
    startTime=millis();
  }

  //Check if the buttong is held for more than 50 ms.
  if(millis()-startTime > debounceTime)
  {

    //Check if there is a transition.
    if(buttonReading!=currButtonState)
    {
      //Set the new button state to the reading.
      currButtonState=buttonReading;

      if(currButtonState==HIGH)
      {
        ledState=!ledState;
      }
    }
  }

  digitalWrite(ledPin,ledState);

  //Save the reading.
  lastButtonState=buttonReading;
}

