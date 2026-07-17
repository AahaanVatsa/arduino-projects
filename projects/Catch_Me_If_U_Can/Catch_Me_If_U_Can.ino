//Includes the Liquid Crystal library and declares the LCD variables
#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7, sw1 = 8, buzzer = 9;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
//Declares the rest of the variables
int num;
int special = 54;
//This contains the pinmodes and all of the code
void setup()
{
  //Starts the LCD and declares the pinmodes
  lcd.begin(16,2);
  pinMode(sw1, INPUT);
  pinMode(buzzer,OUTPUT);
  //This will make num become a different number every 250 milliseconds while the button is not pressed
  while(digitalRead(sw1)==HIGH)
  {
    lcd.clear();
    num = random(0,100);
    lcd.print(num);
    delay(250);
  }
  //When the button is pressed and num is equal to 0
  if(num == 0)
  {
    lcd.setCursor(0,0);
    lcd.print("Num: ");
    lcd.print(num);
    delay(2000);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Game Over!");
    tone(buzzer,300);
    delay(200);
    tone(buzzer, 200);
    delay(200);
    tone(buzzer, 100);
    delay(200);
    noTone(buzzer);
  }
  //When the button is pressed and num is equal to the special number(54)
  else if(num == special)
  {
    lcd.setCursor(0,0);
    lcd.print("Num: ");
    lcd.print(num);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Congrats!!");
    lcd.setCursor(0,1);
    lcd.print("WIN: 100 POINTS!");
    tone(buzzer,300);
    delay(150);
    tone(buzzer,400);
    delay(150);
    tone(buzzer,500);
    delay(150);
    tone(buzzer,400);
    delay(150);
    tone(buzzer,500);
    delay(300);
    noTone(buzzer);
  }
  //When the button is pressed and num is an even number but not a multiple of 10
  else if(num%2 == 0 && num%10 != 0)
  {
    lcd.setCursor(0,0);
    lcd.print("Num: ");
    lcd.print(num);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WIN: ");
    lcd.setCursor(0,1);
    lcd.print("20 Points!");
    tone(buzzer,200);
    delay(200);
    tone(buzzer,300);
    delay(200);
    tone(buzzer,400);
    delay(200);
    noTone(buzzer);
  }
  //When the button is pressed and num is a multiple of 10
  else if(num%2 == 0 && num%10 == 0)
  {
    lcd.setCursor(0,0);
    lcd.print("Num: ");
    lcd.print(num);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WIN: ");
    lcd.setCursor(0,1);
    lcd.print("50 Points!");
    tone(buzzer,450);
    delay(1000);
    noTone(buzzer);
  }
  //When the button is pressed and num is an odd number
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Num: ");
    lcd.print(num);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WIN: ");
    lcd.setCursor(0,1);
    lcd.print("0 Points :(");
    tone(buzzer,100);
    delay(1000);
    noTone(buzzer);
  }
}
void loop(){}
