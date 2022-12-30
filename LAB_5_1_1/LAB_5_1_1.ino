int vResistor = A0; //A0 핀에 가변저항 연결

void setup() {
  Serial.begin(9600);
  pinMode(vResistor, INPUT);
}

void loop() {
  Serial.println(analogRead(vResistor)); //가변저항 값을 읽어 출력
  delay(1000); //1초 대기
}
