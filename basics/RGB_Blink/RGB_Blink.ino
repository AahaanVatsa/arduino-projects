int red = 3, green = 5, blue = 6;
void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}
void loop()
{
  analogWrite(red, 255);
  analogWrite(green, 255);
  delay(500);
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 255);
  delay(500);
  analogWrite(green, 0);
  analogWrite(blue, 255);
  analogWrite(red, 255);
  delay(500);
  analogWrite(blue, 0);
  analogWrite(red, 0);
  analogWrite(green, 0);
}
