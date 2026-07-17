#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Ultrasonic.h>
Ultrasonic sensor(8, 9);
const int s1 = 5;
const int s2 = 4;
const int rLed = 7;
const int gLed = 6;
const int buzzer = 12;
int reading1;
int reading2;
int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
int halt = 50;
int mode = 0;
int units = 1;
float distance;
float scaleFactor = 1.1;
void setup()
{
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  reading1 = digitalRead(s1);
  if (reading1 != lastButtonState1)
  {
    tone(buzzer, 300);
    digitalWrite(rLed, HIGH);
    delay(halt);
    noTone(buzzer);
    digitalWrite(rLed, LOW);
    lastButtonState1 = reading1;
    reading1 = digitalRead(s1);
    if (reading1 == HIGH)
    {
      mode = (mode + 1) % 2;
      units = 1;
      lcd.clear();
    }
  }
  reading2 = digitalRead(s2);
  if (reading2 != lastButtonState2)
  {
    tone(buzzer, 300);
    digitalWrite(gLed, HIGH);
    delay(halt);
    noTone(buzzer);
    digitalWrite(gLed, LOW);
    lastButtonState2 = reading2;
    reading2 = digitalRead(s2);
    if (reading2 == HIGH)
    {
      units++;
      if (units > 3) units = 1;
      lcd.clear();
    }
  }
  distance = sensor.read() * scaleFactor;
  if (mode == 0)
  {
    if (units == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("Distance in mm: ");
      lcd.setCursor(0, 1);
      lcd.print(distance * 10);
    }
    else if (units == 2)
    {
      lcd.setCursor(0, 0);
      lcd.print("Distance in cm: ");
      lcd.setCursor(0, 1);
      lcd.print(distance);
    }
    else if (units == 3)
    {
      lcd.setCursor(0, 0);
      lcd.print("Distance in m: ");
      lcd.setCursor(0, 1);
      lcd.print(distance / 100);
    }
  }

  if (mode == 1)
  {
    if (units == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("Distance in in: ");
      lcd.setCursor(0, 1);
      lcd.print(distance / 2.54);
    }
    else if (units == 2)
    {
      lcd.setCursor(0, 0);
      lcd.print("Distance in ft: ");
      lcd.setCursor(0, 1);
      lcd.print(distance / 30.48);
    }
    else if (units == 3)
    {
      lcd.setCursor(0, 0);
      lcd.print("Distance in yd: ");
      lcd.setCursor(0, 1);
      lcd.print(distance / 91.44);
    }
  }
  delay(100);
}
