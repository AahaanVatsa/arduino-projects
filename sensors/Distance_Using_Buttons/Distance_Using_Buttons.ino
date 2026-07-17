#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Ultrasonic.h>
Ultrasonic sensor(8, 9);
const int buttonPin1 = 5;
int reading1;
int lastButtonState1 = LOW;
const int buttonPin2 = 4;
int reading2;
int lastButtonState2 = LOW;
const int buzzer = 12;
int halt = 50;
int mode = 1;
float distance;
float scaleFactor = 1.1;
void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
}
void loop()
{
  reading1 = digitalRead(buttonPin1);
  if  (reading1 != lastButtonState1)
  {
    delay(halt);
    lastButtonState1 = reading1;
    if (reading1 == HIGH)
    {
      lcd.clear();
      tone(buzzer, 300);
      if (mode < 3)
      {
        mode++;
      }
      else
      {
        mode = 1;
      }
      delay(100);
      noTone(buzzer);
    }
  }
  reading2 = digitalRead(buttonPin2);
  if (reading2 != lastButtonState2)
  {
    delay(halt);
    lastButtonState2 = reading2;
    if (reading2 == HIGH)
    {
      tone(buzzer, 300);
      distance = sensor.read();
      distance = distance * scaleFactor;
      delay(100);
      noTone(buzzer);
      lcd.clear();
    }
  }
  if (mode == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("Distance in mm");
    lcd.setCursor(0, 1);
    lcd.print(distance * 10);
  }
  else if (mode == 2)
  {
    lcd.setCursor(0, 0);
    lcd.print("Distance in cm");
    lcd.setCursor(0, 1);
    lcd.print(distance);
  }

  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Distance in inch");
    lcd.setCursor(0, 1);
    lcd.print(distance / 2.54);
  }
}
