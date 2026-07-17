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
float scaleFactor = 1.1;
float length;
float breadth;
float area;
void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
}
void loop() {
  reading1 = digitalRead(buttonPin1);
  if (reading1 != lastButtonState1) {
    delay(halt);
    lastButtonState1 = reading1;
    if (reading1 == HIGH) {
      digitalWrite(buzzer, HIGH);
      length = sensor.read();
      length = length * scaleFactor;
      delay(100);
      digitalWrite(buzzer, LOW);
      lcd.clear();
    }
  }
  reading2 = digitalRead(buttonPin2);
  if (reading2 != lastButtonState2) {
    delay(halt);
    lastButtonState2 = reading2;
    if (reading2 == HIGH) {
      digitalWrite(buzzer, HIGH);
      breadth = sensor.read();
      breadth = breadth * scaleFactor;
      delay(100);
      digitalWrite(buzzer, LOW);
      lcd.clear();
    }
  }
  area = length * breadth;
  lcd.setCursor(0, 0);
  lcd.print("L:");
  lcd.print(length);
  lcd.print(" ");
  lcd.print("B:");
  lcd.print(breadth);
  lcd.setCursor(0, 1);
  lcd.print("Area : ");
  lcd.print(area);
}
