//i2c Master Code(UNO)
#include <Wire.h>

const int buttonPin = 2;    // the number of the pushbutton pin
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
const int buttonPin6 = 7;
const int ledPin =  13;      // the number of the LED pin
const int timerT =  11;

int buttonState = 0; 
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;

int firstplayer;
int prevplayer;
bool loopedOnce;

int gameTime = 0;
boolean gameState = false;
boolean endGame = false;

int ledState = LOW; 
unsigned long previousMillis = 0;  
const long interval = 2000; 
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(timerT, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  
  randomSeed(analogRead(0));
  loopedOnce = false;
  
}

void game() {
  if (loopedOnce == false) {
    firstplayer = random(1,4);
    loopedOnce = true;
    //delay(50);

    if(firstplayer == 1){
    Wire.beginTransmission(5);
    Wire.write('A');
    Wire.write('D');
    Wire.write('F');
    Wire.endTransmission();
  }
  if(firstplayer == 2){
    Wire.beginTransmission(5);
    Wire.write('C');
    Wire.write('B');
    Wire.write('F');
    Wire.endTransmission();
  }
  if(firstplayer == 3){
    Wire.beginTransmission(5);
    Wire.write('E');
    Wire.write('B');
    Wire.write('D');
    Wire.endTransmission();
  }

  }

  Serial.println(firstplayer);
  
//  // read the state of the pushbutton value:
//    buttonState = digitalRead(buttonPin);
//    buttonState2 = digitalRead(buttonPin2);
//    buttonState3 = digitalRead(buttonPin3);
//    buttonState4 = digitalRead(buttonPin4);
//    buttonState5 = digitalRead(buttonPin5);
//    buttonState6 = digitalRead(buttonPin6);
//    
//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//    
//    //Right button pressed
//    
//    //Right Buttons
//
// if(endGame != 0) {
//    //First Player, Right
//    if (buttonState == HIGH) {
//      Wire.beginTransmission(5);
//      Wire.write('C');
//      Wire.write('B');
//      Wire.endTransmission();
//    
//    }
//    //Second Player, Right
//    if (buttonState2 == HIGH) {
//      Wire.beginTransmission(5);
//      Wire.write('E');
//      Wire.write('D');
//      Wire.endTransmission();
//    
//    }
//    //Third Player, Right
//    if (buttonState3 == HIGH) {
//      Wire.beginTransmission(5);
//      Wire.write('A');
//      Wire.write('F');
//      Wire.endTransmission();
//    
//    }
//    //Left Buttons
//    //First Player, Left
//    if(buttonState4 == HIGH){
//      Wire.beginTransmission(5);
//      Wire.write('E');
//      Wire.write('B');
//      Wire.endTransmission();
//    }
//    //Second Player, Left
//    if(buttonState5 == HIGH){
//      Wire.beginTransmission(5);
//      Wire.write('A');
//      Wire.write('D');
//      Wire.endTransmission();
//    }
//    //Third Player, Left
//    if(buttonState6 == HIGH){
//      Wire.beginTransmission(5);
//      Wire.write('C');
//      Wire.write('F');
//      Wire.endTransmission();
//    }
//    
// }  
////    else {
////      Wire.beginTransmission(5);
////      Wire.write('L');
////      Wire.endTransmission();
////    }
}

void loop()
{
  // if game time is not 0, keep playing the game
  unsigned long currentMillis = millis();

  if(gameState == false && buttonState6 == 1) {
    gameTime = random(10,20) * 1000;
    game();
    gameState = true;
  }

  if(gameTime == 0 && gameState == true) {
    endGame = true;
  }

  if(gameTime !=0) {
    if (currentMillis - previousMillis >= interval) {
      //save the last time you blinked the LED
      previousMillis = currentMillis;
      gameTime -= 1000;
      Serial.println(gameTime/1000);

      if(gameTime > 5000) {
        digitalWrite(timerT, HIGH);
      }
      
      if (gameTime < 5000) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      digitalWrite(timerT, ledState);
      
  }
 }
// ------------------------------------------//
   
  
  // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
    buttonState4 = digitalRead(buttonPin4);
    buttonState5 = digitalRead(buttonPin5);
    buttonState6 = digitalRead(buttonPin6);
    
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    
    //Right button pressed
    
    //Right Buttons

 if(endGame != true) {
    //First Player, Right
    if (buttonState == HIGH) {
      Wire.beginTransmission(5);
      Wire.write('C');
      Wire.write('B');
      Wire.endTransmission();
    
    }
    //Second Player, Right
    if (buttonState2 == HIGH) {
      Wire.beginTransmission(5);
      Wire.write('E');
      Wire.write('D');
      Wire.endTransmission();
    
    }
    //Third Player, Right
    if (buttonState3 == HIGH) {
      Wire.beginTransmission(5);
      Wire.write('A');
      Wire.write('F');
      Wire.endTransmission();
    
    }
    //Left Buttons
    //First Player, Left
    if(buttonState4 == HIGH){
      Wire.beginTransmission(5);
      Wire.write('E');
      Wire.write('B');
      Wire.endTransmission();
    }
    //Second Player, Left
    if(buttonState5 == HIGH){
      Wire.beginTransmission(5);
      Wire.write('A');
      Wire.write('D');
      Wire.endTransmission();
    }
    //Third Player, Left
    if(buttonState6 == HIGH){
      Wire.beginTransmission(5);
      Wire.write('C');
      Wire.write('F');
      Wire.endTransmission();
    }
    
 }  
}
//  if(gameTime != 0) {
//    digitalWrite(timerT,HIGH);
//    //i++;
//    game();
//  }
//  game();
//  unsigned long currentMillis = millis();
//
//  if (currentMillis - previousMillis >= interval) {
//    // save the last time you blinked the LED
//    previousMillis = currentMillis;
//
//    // if the LED is off turn it on and vice-versa:
//    if (ledState == LOW) {
//      ledState = HIGH;
//    } else {
//      ledState = LOW;
//    }
//
//    // set the LED with the ledState of the variable:
//    digitalWrite(timerT, ledState);
  
  
