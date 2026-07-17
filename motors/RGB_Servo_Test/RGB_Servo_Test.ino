#include <Servo.h>

Servo myServo;

int red = 6;
int blue = 5;
int green = 3;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  myServo.attach(11);
}

void loop() {

  // Sweep from 0° to 180°
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);

    // Purple
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 255);

    delay(30);
  }

  // Sweep from 180° to 0°
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);

    // Yellow
    analogWrite(red, 255);
    analogWrite(green, 70);
    analogWrite(blue, 0);

    delay(30);
  }

  // Sweep from 0° to 180°
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);

    // Cyan
    analogWrite(red, 0);
    analogWrite(green, 60);
    analogWrite(blue, 255);

    delay(30);
  }

  // Sweep from 180° to 0°
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);

    // White
    analogWrite(red, 255);
    analogWrite(green, 65);
    analogWrite(blue, 255);

    delay(30);
  }
}
