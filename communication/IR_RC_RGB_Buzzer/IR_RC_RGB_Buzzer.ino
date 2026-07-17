#include <IRremote.hpp>
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
int red = 3, green = 5, blue = 6, buzzer = 9;
int delayValue = 300;
void(*resetFunc)(void)=0;
void setup()
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  IrReceiver.begin(2);
}
void loop()
{
  while(IrReceiver.decode()==0)
  {}
  if(IrReceiver.decode())
  {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    switch(code)
    {
      case 3910598400://0
      Serial.println("You Pressed Zero");
      playTone();
      break;

      case 4077715200://1
      Serial.println("You Pressed One");
      delayValue = 400;
      playTone();
      break;

      case 3877175040://2
      Serial.println("You Pressed Two");
      delayValue = 600;
      playTone();
      break;

      case 2707357440://3
      Serial.println("You Pressed Three");
      delayValue = 800;
      playTone();
      break;

      case 4144561920://4
      Serial.println("You Pressed Four");
      delayValue = 1000;
      playTone();
      break;

      case 3810328320://5
      Serial.println("You Pressed Five");
      delayValue = 1500;
      playTone();
      break;

      case 2774204160://6
      Serial.println("You Pressed Six");
      delayValue = 2000;
      playTone();
      break;
    }
    IrReceiver.resume();
  }
}
void playTone()
{
  tone(buzzer,240,500);
  analogWrite(red,255);
  analogWrite(green,0);
  analogWrite(blue,0);
  delay(delayValue);

  tone(buzzer,270,500);
  analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,0);
  delay(delayValue);

  tone(buzzer,300,500);
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,255);
  delay(delayValue);

  tone(buzzer,337.5,500);
  analogWrite(red,255);
  analogWrite(green,105);
  analogWrite(blue,0);
  delay(delayValue);

  tone(buzzer,360,500);
  analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,255);
  delay(delayValue);

  tone(buzzer,400,500);
  analogWrite(red,255);
  analogWrite(green,0);
  analogWrite(blue,255);
  delay(delayValue);

  tone(buzzer,450,500);
  analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,255);
  delay(delayValue);
  delay(1000);

  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);
  resetFunc();
}
