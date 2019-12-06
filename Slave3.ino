//i2c Slave Code(Leonardo)
#include <Wire.h>
const int yellow = 2;
void setup()
{
  Wire.begin(5);
  Wire.onReceive(receiveEvent);

 
  pinMode(2,OUTPUT);
  
  
}
void loop()
{
  delay(100);
}

void receiveEvent(int howMany)
{
  while(Wire.available())
  {
    char c = Wire.read();

    if (c == 'E'){
      digitalWrite (2,HIGH);
    }

    if (c == 'F'){
      digitalWrite (2,LOW);
    }

  if (c == 'L'){
    digitalWrite(2,LOW);
  }
  }
}
