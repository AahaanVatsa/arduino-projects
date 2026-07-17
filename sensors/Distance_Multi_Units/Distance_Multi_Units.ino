#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Ultrasonic.h>
Ultrasonic sensor(8, 9);
float scaleFactor = 1.1;
float distance;
void setup()
{
  lcd.init();
  lcd.backlight();
}
void loop()
{
  distance = sensor.read();
  distance = distance*scaleFactor;
  lcd.setCursor(0,0);
  lcd.print("Distance in mm: ");
  lcd.setCursor(0,1);
  lcd.print(distance*10);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance in cm: ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance in in: ");
  lcd.setCursor(0,1);
  lcd.print(distance/2.54);
  delay(1000);
  lcd.clear();
}
