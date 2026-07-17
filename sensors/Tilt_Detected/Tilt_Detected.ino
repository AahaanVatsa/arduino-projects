unsigned long passedTime;
int led = 3, tilt = 4, buzzer = 5;
void (*resetFunc)(void)=0;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(tilt, INPUT);
  pinMode(buzzer, OUTPUT);
}
void loop()
{
  if(digitalRead(tilt)==HIGH)
  {
    Serial.println("'******Tilt Detected******");
    for(int i=300;i<=700;i+20)
    {
      digitalWrite(led, HIGH);
      tone(buzzer, i);
      delay(30);
      digitalWrite(led,LOW);
      noTone(buzzer);
      delay(30);        
    } 
    resetFunc();
  }
  else
  {
    Serial.print("Time in Seconds: ");
    passedTime = millis()/1000;
    Serial.println(passedTime);
    delay(1000);
  }
}
