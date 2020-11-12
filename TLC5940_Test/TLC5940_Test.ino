#include "Tlc5940.h"

void setup()
{
  Tlc.init(0);
}


void loop()
{
  Tlc.set(0, 4095);
  Tlc.update();

  delay(1000); 

  for (int i = 0; i < 4096; i += 100)
  {
    for (int j = 0; j < 16; j++)
    {
      Tlc.set(j, i);
      Tlc.update();
    }

    delay(100);
  }
}
