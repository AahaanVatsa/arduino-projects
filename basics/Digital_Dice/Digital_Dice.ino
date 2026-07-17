int dice = 0;
const int button = 10, a = 9, b = 8, c = 7, d = 6, e = 5, f = 4, g = 3, dot = 2;
void setup()
{
  pinMode(button, INPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dot, OUTPUT);
  randomSeed(analogRead(A1));
}
void loop()
{
 digitalWrite(a, LOW);
 digitalWrite(b, LOW); 
 digitalWrite(c, LOW);
 digitalWrite(d, LOW);
 digitalWrite(e, LOW);
 digitalWrite(f, LOW); 
 digitalWrite(g, LOW);
 digitalWrite(dot, LOW);
 while(digitalRead(button)==LOW)
 {
  dice = random(1,7);
  if(dice==1)
  {
    pinMode(a, LOW);
    pinMode(b, HIGH);
    pinMode(c, HIGH);
    pinMode(d, LOW);
    pinMode(e, LOW);
    pinMode(f, LOW);
    pinMode(g, LOW);
    pinMode(dot, LOW);
    delay(2000);
  }
  if(dice==2)
  {
    pinMode(a, HIGH);
    pinMode(b, HIGH);
    pinMode(c, LOW);
    pinMode(d, LOW);
    pinMode(e, HIGH);
    pinMode(f, LOW);
    pinMode(g, HIGH);
    pinMode(dot, LOW);
    delay(2000);
  }
  if(dice==3)
  {
    pinMode(a, HIGH);
    pinMode(b, HIGH);
    pinMode(c, HIGH);
    pinMode(d, HIGH);
    pinMode(e, LOW);
    pinMode(f, LOW);
    pinMode(g, HIGH);
    pinMode(dot, LOW);
    delay(2000);
  }
  if(dice==4)
  {
    pinMode(a, LOW);
    pinMode(b, HIGH);
    pinMode(c, HIGH);
    pinMode(d, LOW);
    pinMode(e, LOW);
    pinMode(f, HIGH);
    pinMode(g, HIGH);
    pinMode(dot, LOW);
    delay(2000);
  }
  if(dice==5)
  {
    pinMode(a, HIGH);
    pinMode(b, LOW);
    pinMode(c, HIGH);
    pinMode(d, HIGH);
    pinMode(e, LOW);
    pinMode(f, HIGH);
    pinMode(g, HIGH);
    pinMode(dot, LOW);
    delay(2000);
  }
  if(dice==6)
  {
    pinMode(a, HIGH);
    pinMode(b, LOW);
    pinMode(c, HIGH);
    pinMode(d, HIGH);
    pinMode(e, HIGH);
    pinMode(f, HIGH);
    pinMode(g, HIGH);
    pinMode(dot, LOW);
    delay(2000);
  }
 }
}
