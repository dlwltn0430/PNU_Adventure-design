void setup() {
  Serial.begin(9600); // 컴퓨터와의 시리얼 연결
  Serial1.begin(9600); // 우노와의 시리얼 연결
}

void loop() {
  char buf[128];
  int len = 0;
  while (1) {
    while (Serial1.available()) { // 우노로부터 데이터 수신
      char data = Serial1.read();
      if (data == '\n') {
        buf[len] = '\0';
        String in_str = buf;
        Serial.println("Current temperature : " + in_str);
        len = 0;
        break;
      }
      buf[len++] = data;
    }  
  }
}
