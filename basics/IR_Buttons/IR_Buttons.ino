#include <IRremote.hpp>
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
int led = 3;
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  IrReceiver.begin(2);
}
void loop()
{
  while(IrReceiver.decode()==0)
  {
    digitalWrite(led,LOW);
    delay(100);
  }
  if(IrReceiver.decode())
  {
    unsigned long value = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("KEY Value in DEC= ");
    Serial.println(value,DEC);
    digitalWrite(led,HIGH);
    delay(200);
  }
  IrReceiver.resume();
}
