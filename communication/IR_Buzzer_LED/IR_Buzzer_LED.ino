int ir = 7;
int buzz = 8;
int green = 6;
int red = 4;
void setup()
{
  pinMode(ir, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}
void loop()
{
  if(digitalRead(ir)==HIGH)
  {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    tone(buzz, 300);
    delay(500);
  }
  else
  {
    noTone(buzz);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }
}
