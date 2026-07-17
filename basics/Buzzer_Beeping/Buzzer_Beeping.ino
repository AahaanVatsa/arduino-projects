int buzz = 3;
char a;
void setup() 
{
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  Serial.println("---Start Serial Monitor---");
  Serial.println("Enter something in the box and enter.");
  Serial.println("To turn ON: enter 1.");
  Serial.println("To turn OFF: enter 0.");
  Serial.println();
}

void loop() 
{
  if(Serial.available()>0)
  {
   a = Serial.read();
   Serial.print("You Pressed: ");
   Serial.println(a);
   if(a='1')
   {
    tone(buzz, 1000);
    Serial.println("BUZZER ON!");
   }
   if(a='0')
   {
    noTone(buzz);
    Serial.println("BUZZER OFF!");
   }
  }
}
