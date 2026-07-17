#include <Servo.h>
#include <Ultrasonic.h>

Ultrasonic sensor(9, 8);
Servo myServo;

float distance;
float scale_factor = 1.1;

int red = 6;
int blue = 5;
int green = 3;

void updateLED(float distance) {

  if (distance < 10)
    distance = 10;
  if (distance > 25)
    distance = 25;

  int redValue = map(distance, 25, 10, 0, 255);
  int greenValue = map(distance, 25, 10, 70, 0);   // Max green = 70

  analogWrite(red, redValue);
  analogWrite(green, greenValue);
  analogWrite(blue, 0);
}

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  Serial.begin(9600);

  myServo.attach(11);
}

void loop() {

  // Sweep from 0° to 180°
  for (int angle = 0; angle <= 180; angle += 2) {
    myServo.write(angle);
    delay(150);

    distance = sensor.read();
    distance *= scale_factor;

    updateLED(distance);

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("  Distance: ");
    Serial.println(distance);
  }

  // Sweep from 180° to 0°
  for (int angle = 180; angle >= 0; angle -= 2) {
    myServo.write(angle);
    delay(150);

    distance = sensor.read();
    distance *= scale_factor;

    updateLED(distance);

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("  Distance: ");
    Serial.println(distance);
  }
}
