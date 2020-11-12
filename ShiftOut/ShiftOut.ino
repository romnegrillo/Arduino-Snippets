// Shift Out Register: 74HC595
// Output Pins: Q0 - Q7
// Vcc - 5V
// GND - GND
// OE - GND
// MR - 5V

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

byte binToCompare = 0b00001111;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  shiftWrite(0x00);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    byte num = Serial.parseInt();

    if (num >= 0 && num <= 255)
    {
      Serial.print("Binary input: ");
      Serial.println(num, BIN);

      Serial.print("AND Result: ");
      Serial.println(num & binToCompare, BIN);
      shiftWrite(num & binToCompare);

      delay(2000);

      Serial.print("OR Result: ");
      Serial.println(num ^ binToCompare, BIN);
      shiftWrite(num ^ binToCompare);

      delay(2000);

      Serial.print("NOT Result: ");
      Serial.println(~num, BIN);
      shiftWrite(~num);
    }
    else
    {
      Serial.println("Value greater than byte!");
    }
  }
}

void shiftWrite(byte value)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}

