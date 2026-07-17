#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Ultrasonic.h>
Ultrasonic sensor(8, 9);
const int s1 = 5;
const int s2 = 4;
int reading1;
int reading2;
int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
int halt = 50;
int metric = 1;
int customary = 1;
float distance;
float scaleFactor = 1.1;
void setup()
{
  pinMode(s1, INPUT);
  lcd.init();
  lcd.backlight();
}
void loop()
{
  reading1 = digitalRead(s1);
  if((reading1 != lastButtonState1) && (reading2 == LOW))
  {
    delay(halt);
    lastButtonState1 = reading1;
    if(reading1 == HIGH)
    {
      if(metric<3)
      {
        metric++;
      }
      else
      {
        metric = 1;
      }
    }
  }
  distance = sensor.read();
  distance = distance*scaleFactor;
  if(metric == 1)
  {
    lcd.setCursor(0,0);
    lcd.print("Distance in mm: ");
    lcd.setCursor(0,1);
    lcd.print(distance*10);
    delay(800);
    lcd.clear();
  }
  else if(metric == 2)
  {
    lcd.setCursor(0,0);
    lcd.print("Distance in cm: ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    delay(800);
    lcd.clear();
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Distance in m: ");
    lcd.setCursor(0,1);
    lcd.print(distance/100);
    delay(800);
    lcd.clear();
  }
  reading2 = digitalRead(s2);
  if((reading2 != lastButtonState2) && (reading1 == LOW))
  {
    delay(halt);
    lastButtonState2 = reading2;
    if(reading2 == HIGH)
    {
      if(customary<3)
      {
        customary++;
      }
      else
      {
        customary = 1;
      }
    }
  }
  distance = sensor.read();
  distance = distance*scaleFactor;
  if(customary == 1)
  {
    lcd.setCursor(0,0);
    lcd.print("Distance in in: ");
    lcd.setCursor(0,1);
    lcd.print(distance/2.54);
    delay(800);
    lcd.clear();
  }
  else if(customary == 2)
  {
    lcd.setCursor(0,0);
    lcd.print("Distance in ft: ");
    lcd.setCursor(0,1);
    lcd.print(distance/30.48);
    delay(800);
    lcd.clear();
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Distance in yd: ");
    lcd.setCursor(0,1);
    lcd.print(distance/91.44);
    delay(800);
    lcd.clear();
  }
}
