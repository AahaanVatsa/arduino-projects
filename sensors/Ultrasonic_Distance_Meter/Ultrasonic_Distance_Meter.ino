#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Ultrasonic.h>
Ultrasonic sensor(8,9);
float distance;
float scaleFactor = 1.2027322;
void setup()
{
  lcd.init();
  lcd.backlight();
}
void loop()
{
  distance = sensor.read();
  distance = distance;
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");
  delay(600);
  lcd.clear();
}
