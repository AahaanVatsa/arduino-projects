#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7, button = 8, buzzer = 9;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
long num = 0;
void setup()
{
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
  while(digitalRead(button)==HIGH)
  {
    lcd.clear();
    lcd.print(num);
    delay(10);
    num++;
  }
  if(num >= 50 and num < 100)
  {
    lcd.setCursor(0,0);
    lcd.print("Super Jackpot!!");
    lcd.setCursor(0,1);
    lcd.print("You won 100 coins!");
    delay(1000);
    lcd.scrollDisplayLeft();
    for(int i = 700; i >= 400; i = i-10)
    {
      tone(buzzer,i);
      delay(40);
    }
    noTone(buzzer);
  }
  else if(num >= 100 and num < 200)
  {
    lcd.setCursor(0,0);
    lcd.print("Great Jackpot!!");
    lcd.setCursor(0,1);
    lcd.print("You won 30 coins!");
    delay(1000);
    lcd.scrollDisplayLeft();
    for(int i = 400; i >= 700; i = i+10)
    {
      tone(buzzer,i);
      delay(40);
    }
    noTone(buzzer);
  }
  else if(num >= 200 and num < 300)
  {
    lcd.setCursor(0,0);
    lcd.print("Nice Jackpot!!");
    lcd.setCursor(0,1);
    lcd.print("You won 20 coins!");
    delay(1000);
    lcd.scrollDisplayLeft();
    for(int i = 400; i >= 700; i = i+10)
    {
      tone(buzzer,i);
      delay(40);
    }
    noTone(buzzer);
  }
  else if(num >= 300 and num < 400)
  {
    lcd.setCursor(0,0);
    lcd.print("Jackpot!");
    lcd.setCursor(0,1);
    lcd.print("You won 10 coins!");
    delay(1000);
    lcd.scrollDisplayLeft();
    for(int i = 400; i >= 700; i = i+10)
    {
      tone(buzzer,i);
      delay(40);
    }
    noTone(buzzer);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Womp Womp :(");
    lcd.setCursor(0,1);
    lcd.print("You Lost!");
    delay(1000);
    tone(buzzer, 500);
    delay(100);
    tone(buzzer, 400);
    delay(100);
    tone(buzzer, 300);
    delay(100);
    noTone(buzzer);
  }
}
void loop(){}
