#include <LiquidCrystal.h>
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

const int sw1 = 4;
const int sw2 = 3;
const int buzz = 2;
const int pot = A0;

int password[4] = {5, 2, 8, 1};
int entered[4] = {0, 0, 0, 0};

int currentPosition = 0;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup(){
  pinMode(buzz, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  lcd.begin(16,2);
  lcd.clear();
}

void accessGrantedSound(){
  tone(buzz, 1000, 150);
  delay(180);

  tone(buzz, 1500, 150);
  delay(180);

  tone(buzz, 2000 ,300);
  delay(360);

  noTone(buzz);
}

void accessDeniedSound(){
  tone(buzz, 400, 300);
  delay(350);

  tone(buzz, 300, 300);
  delay(350);

  tone(buzz, 200, 500);
  delay(550);

  noTone(buzz);
}

void loop() {
    int potValue = analogRead(pot);
    int digit = map(potValue, 0, 1023, 0, 9);

    entered[currentPosition] = digit;

    lcd.setCursor(0,0);
    lcd.print("Code:");
    lcd.setCursor(0,1);
    for(int i = 0; i < 4; i++){
      lcd.print(entered[i]);
      lcd.print(" ");
    }

    while(digitalRead(sw1) == LOW){
      delay(20);
      if(currentPosition < 3){
        currentPosition++;
      }
      else {
        currentPosition = 0;
      }
    }

    while(digitalRead(sw2) == LOW){
      delay(20);
      bool correct = true;

      for(int i = 0; i < 4; i++){
        if(entered[i] != password[i]){
          correct = false;
        }
      }

      if(correct){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Access Granted");
        accessGrantedSound();
      }
      else{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Access Denied");
        accessDeniedSound();
      }
      delay(2000);
      
      currentPosition = 0;
      for(int i = 0; i < 4; i++){
        entered[i] = 0;
      }
    }
    
}
