#include <IRremote.hpp>
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
int red = 3, green = 5, blue = 6;
void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  IrReceiver.begin(11);
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
      case 3910598400: //Number 0
      Serial.println("You Pressed Zero.");
      for(int pwm = 0; pwm<=255; pwm++)
      {
        analogWrite(green,pwm);
        analogWrite(red,0);
        analogWrite(blue,0);
        delay(10);
      }
      for(int pwm = 255; pwm>=0; pwm--)
      {
        analogWrite(green,pwm);
        analogWrite(red,0);
        analogWrite(blue,0);
        delay(10);
      }
      for(int pwm = 0; pwm<=255; pwm++)
      {
        analogWrite(blue,pwm);
        analogWrite(red,0);
        analogWrite(green,0);
        delay(10);
      }
      for(int pwm = 255; pwm>=0; pwm--)
      {
        analogWrite(blue,pwm);
        analogWrite(red,0);
        analogWrite(green,0);
        delay(10);
      }
      break;
      
      case 4077715200: //Number 1
      Serial.println("You Pressed One.");
      analogWrite(red, 255);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      break;

      case 3877175040: //Number 2
      Serial.println("You Pressed Two.");
      analogWrite(red, 0);
      analogWrite(green, 255);
      analogWrite(blue, 0);
      break;

      case 2707357440: //Number 3
      Serial.println("You Pressed Three.");
      analogWrite(red, 0);
      analogWrite(green, 0);
      analogWrite(blue, 255);
      break;

      case 4144561920: //Number 4
      Serial.println("You Pressed Four.");
      analogWrite(red, 255);
      analogWrite(green, 105);
      analogWrite(blue, 0);
      break;

      case 3810328320: //Number 5
      Serial.println("You Pressed Five.");
      analogWrite(red, 0);
      analogWrite(green, 255);
      analogWrite(blue, 255);
      break;

      case 2774204160: //Number 6
      Serial.println("You Pressed Six.");
      analogWrite(red, 255);
      analogWrite(green, 0);
      analogWrite(blue, 255);
      break;

      case 3175284480: //Number 7
      Serial.println("You Pressed Seven.");
      analogWrite(red, 255);
      analogWrite(green, 0);
      analogWrite(blue, 80);
      break;

      case 2907897600: //Number 8
      Serial.println("You Pressed Eight.");
      analogWrite(red, 255);
      analogWrite(green, 40);
      analogWrite(blue, 0);
      break;

      case 3041591040: //Number 9
      Serial.println("You Pressed Nine.");
      analogWrite(red, 255);
      analogWrite(green, 255);
      analogWrite(blue, 255);
      break;

      case 4127850240: //EQ
      Serial.println("You Pressed Off");
      analogWrite(red,0);
      analogWrite(green,0);
      analogWrite(blue,0);
      break;
   }
      IrReceiver.resume();
  }
 }
