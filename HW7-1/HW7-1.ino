int pins_LED[] = {2,3,4,5};

void setup() {
  Serial.begin(9600);
  for (int i=0; i<4; i++) {
    pinMode(pins_LED[i], OUTPUT);
  }
}

void loop() {
  int reading = analogRead(56);
    if (reading < 150) {
      for (int i=0; i<4; i++) {
      digitalWrite(pins_LED[i], LOW);
      }
    }
    else if (reading < 300) {
      digitalWrite(pins_LED[0], HIGH);
      digitalWrite(pins_LED[1], LOW);
      digitalWrite(pins_LED[2], LOW);
      digitalWrite(pins_LED[3], LOW);
    }
    else if (reading < 450) {
      digitalWrite(pins_LED[0], HIGH);
      digitalWrite(pins_LED[1], HIGH);
      digitalWrite(pins_LED[2], LOW);
      digitalWrite(pins_LED[3], LOW);
    }
    else if (reading < 600) {
      digitalWrite(pins_LED[0], HIGH);
      digitalWrite(pins_LED[1], HIGH);
      digitalWrite(pins_LED[2], HIGH);
      digitalWrite(pins_LED[3], LOW);
    }
    else {
      for (int i=0; i<4; i++) {
        digitalWrite(pins_LED[i], HIGH);
      }
    }
}
