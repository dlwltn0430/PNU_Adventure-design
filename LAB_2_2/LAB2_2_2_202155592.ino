void setup() {
  Serial.begin(9600);
}

void loop() {
  int n = 123;
  float f = 3.1415927;

  Serial.println(n, BIN); //이진수
  Serial.println(n, DEC); //십진수, 디폴트값으로 DEC는 생략 가능
  Serial.println(n, HEX); //십육진수

  Serial.println();
  Serial.println(f);
  Serial.println(f,5);

  while(true);
}
