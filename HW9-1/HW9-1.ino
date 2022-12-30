#include <Servo.h>

Servo myServo;
int pins_button[] = {14,15};
int servoPin = 11;
int angle = 0;

void setup() {
  myServo.attach(servoPin);
  myServo.write(angle);
  for (int i=0 ; i<2; i++) {
    pinMode(pins_button[i], INPUT);
  }
}

void loop() {
  if (digitalRead(pins_button[0])) {
    if (angle <= 170) {
      angle = angle + 10;
      myServo.write(angle);
      delay(1000);
    }
  }

  if (digitalRead(pins_button[1])) {
    if (angle >= 10) {
      angle = angle - 10;
      myServo.write(angle);
      delay(1000);
    }
  }
}
