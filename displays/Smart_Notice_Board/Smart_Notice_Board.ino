#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7, button = 8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int count = 0;
void setup()
{
  pinMode(button, INPUT);
  lcd.begin(16,2);

}
void loop()
{
  while(digitalRead(button)==LOW)
  {
    count++;
    delay(1000);
    if(count==0 or count==4)
    {
      lcd.setCursor(0,0);
      lcd.print("Press the button ");
      lcd.setCursor(0,1);
      lcd.print("to select msg.");
      lcd.clear();
      count = 0;
    }
    if(count==1)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("We are Open!");
    }
    if(count==2)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("We are Closed.");
      lcd.setCursor(0,1);
      lcd.print("Open at 8 AM.");
    }
    if(count==3)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("10% OFF!!");
      lcd.setCursor(0,1);
      lcd.print("TODAY ONLY!");
    }
  }
}
