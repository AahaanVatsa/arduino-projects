int red = 3, green = 5, blue = 6;
char code;
void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()<0)
  {
    code = Serial.read();
    switch (code)
    {
      case 'R':
      analogWrite(red, 255);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      break;
      
      case 'G':
      analogWrite(red, 0);
      analogWrite(green, 255);
      analogWrite(blue, 0);
      break;

      case 'B':
      analogWrite(red, 0);
      analogWrite(green, 0);
      analogWrite(blue, 255);
      break;

      default:
      analogWrite(red, 0);
      analogWrite(green, 0);
      analogWrite(blue, 0);
    }
  }
}
