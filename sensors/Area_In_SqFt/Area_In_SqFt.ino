#include <Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Ultrasonic.h>
Ultrasonic sensor(8, 9);
const int buttonPin1 = 5;
const int buttonPin2 = 4;
const int buzzer = 12;
const int rLed = 7;
const int gLed = 6;
int reading1;
int lastButtonState1 = LOW;
int reading2;
int lastButtonState2 = LOW;
int halt = 50;
float scaleFactor = 1.1;
float length = 0, breadth = 0, area = 0;
void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  lcd.init();
  lcd.backlight();
}
void loop()
{
  reading1 = digitalRead(buttonPin1);
  if (reading1 != lastButtonState1)
  {
    delay(halt);
    lastButtonState1 = reading1;
    if (reading1 == HIGH)
    {
      tone(buzzer, 500);
      digitalWrite(gLed, HIGH);
      digitalWrite(rLed, LOW);
      length = sensor.read();
      length = length * scaleFactor * 0.0328;
      delay(100);
      noTone(buzzer);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Measuring");
      delay(1000);
      digitalWrite(gLed, LOW);
      digitalWrite(rLed, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Length in ft: ");
      lcd.setCursor(0, 1);
      lcd.print(length);
      if (breadth != 0)
      {
        delay(1000);
        lcd.clear();
        area = length * breadth;
        lcd.setCursor(0, 0);
        lcd.print("Area in sqft: ");
        lcd.setCursor(0, 1);
        lcd.print(area);
      }
    }
  }
  reading2 = digitalRead(buttonPin2);
  if (reading2 != lastButtonState2)
  {
    delay(halt);
    lastButtonState2 = reading2;
    if (reading2 == HIGH)
    {
      tone(buzzer, 500);
      digitalWrite(gLed, HIGH);
      digitalWrite(rLed, LOW);
      breadth = sensor.read();
      breadth = breadth * scaleFactor * 0.0328;
      delay(100);
      noTone(buzzer);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Measuring");
      delay(1000);
      digitalWrite(gLed, LOW);
      digitalWrite(rLed, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Breadth in ft: ");
      lcd.setCursor(0, 1);
      lcd.print(breadth);
      if (length != 0)
      {
        delay(1000);
        lcd.clear();
        area = length * breadth;
        lcd.setCursor(0, 0);
        lcd.print("Area in sqft: ");
        lcd.setCursor(0, 10);
        lcd.print(area);
      }
    }
  }
}
