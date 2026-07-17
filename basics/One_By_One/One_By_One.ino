int led_1= 2;
int led_2= 3;
int led_3= 4;
int led_4= 5; 
int led_5= 6;
int led_6= 7;
int led_7= 8;
int led_8= 9;
void setup() 
{
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);
  pinMode(led_8, OUTPUT);
}

void loop() 
{
  digitalWrite(led_1, HIGH);
  delay(1000);
  digitalWrite(led_2, HIGH);
  delay(1000);
  digitalWrite(led_3, HIGH);
  delay(1000);
  digitalWrite(led_4, HIGH);
  delay(1000);
  digitalWrite(led_5, HIGH);
  delay(1000);
  digitalWrite(led_6, HIGH);
  delay(1000);
  digitalWrite(led_7, HIGH);
  delay(1000);
  digitalWrite(led_8, HIGH);
  delay(1000);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  delay(1000);
}
