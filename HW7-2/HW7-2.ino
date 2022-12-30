#include <pitches.h>

int speakerPin = 57;
int melody[] = {0,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5};

void setup() {
  Serial.begin(9600);
  pinMode(A2,INPUT);
}

void loop() {
  int ADC_value = analogRead(A2);
  int i = map(ADC_value,0,1023,0,8);
  tone(speakerPin, melody[i],0);
}
