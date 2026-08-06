#include <LiquidCrystal.h>

// Declare LCD pins
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7); // Initliaze LCD

// Declare RGB LED pins
const int red = 3;
const int green = 5;
const int blue = 6;

// Declare buzzer and button pins
const int buzzer = 4;
const int button = 2;

// Define function to set RGB LED colors
void setColor(int r, int g, int b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}

// Define function to print message
void showMessage(String line1, String line2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}

// Define function for countdown
bool countdown(int r, int g, int b, int duration){
  setColor(r,g,b);

  unsigned long startTime = millis();

  while(millis() - startTime < duration){

    if(digitalRead(button) == LOW){
      return false; // Early press
    }
    
  }

  return true;
}

// Setup componenets as I/O and start LCD
void setup(){

  Serial.begin(9600);

Serial.println("Program Started");
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
  lcd.begin(16,2);
  lcd.clear();

  randomSeed(analogRead(A0)); // Generates different sequence of numbers each time
}

// Main code
void loop(){
  showMessage("Reaction Test", "Press button");
  while(digitalRead(button) == HIGH){
    delay(20);
  }
  while(digitalRead(button) == LOW){}
    delay(20);
    
  long waitTime = random(2000,5001); // Random delay

  showMessage("Get Ready!", "");
  setColor(0,0,255);
  delay(1000);
  showMessage("Waiting...", "");
  delay(waitTime);

  // Red
  if(!countdown(255,0,0,500)){
    showMessage("Too Early", "");
    tone(buzzer,500,500);
    delay(800);

    return;
  }
  // Yellow
  if(!countdown(255,255,0,500)){
    showMessage("Too Early", "");
    tone(buzzer,500,500);
    delay(800);

    return;
  }
  // Green
  if(!countdown(0,255,0,500)){
    showMessage("Too Early", "");
    tone(buzzer,500,500);
    delay(800);

    return;
  }
  
  showMessage("Go!", "");
  setColor(255,255,255); // White
  
  tone(buzzer, 1000, 1000);

  unsigned long startTime = millis();

  while (digitalRead(button) == HIGH){
  }

  unsigned long reactionTime = millis() - startTime;

  showMessage("Reaction Time: ", String(reactionTime) + " ms");

  delay(3000);
}
