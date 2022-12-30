#include <SoftwareSerial.h>

// SoftwareSerial(RX, TX) 형식으로 메가2560의 핀과 교차하여 연결한다.
SoftwareSerial mySerial(4, 5);

void setup() {
  mySerial.begin(9600); // 메가2560과의 시리얼 연결
  Serial.begin(9600); // 컴퓨터와의 시리얼 연결
}

void loop() {
  int reading = analogRead(A0);
  float voltage = reading * 5.0 / 1024.0;
  Serial.print(voltage);
  Serial.print(" V : ");
  float temp = voltage * 100;
  Serial.println(temp);
  mySerial.print(temp + String('\n'));
  delay(1000);
}
