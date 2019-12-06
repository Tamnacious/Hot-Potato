//i2c Slave Code(Leonardo)
#include <Wire.h>
const int green = 2;
const int timerled = 3;
long randtime;
void setup()
{
  int randtime = random(5000, 10000);
  Wire.begin(5);
  Wire.onReceive(receiveEvent);
  
 
  pinMode(2,OUTPUT);
  pinMode(3, OUTPUT);
  
  
  
  /*//Timer
  digitalWrite(3,HIGH);
  delay(randtime);

  int i = 0; 
  while ( i < 8) {
    
    digitalWrite(3,LOW);
    delay(150);
    digitalWrite(3,HIGH);
    delay(150);
    digitalWrite(3,LOW);
    delay(150);
    digitalWrite(3,HIGH);
    delay(150);
    i++;
    digitalWrite(3,LOW);
  }*/
 

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

    if (c == 'A'){
      digitalWrite (2,HIGH);
    }

    if (c == 'B'){
      digitalWrite (2,LOW);
    }

  if (c == 'L'){
    digitalWrite(2,LOW);
  }
  }
}
