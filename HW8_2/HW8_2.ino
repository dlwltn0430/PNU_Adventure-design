#include <LiquidCrystal.h>

LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결
byte user[6] = {B00000, B10000, B00110, B01000, B01000, B00110};

void setup() {
  Serial.begin(9600);
  lcd.createChar(0, user); // 사용자 정의 문자 1 생성
}

void loop() {
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear(); // LCD 화면 지우기
  int reading_temp = analogRead(A1);
  float temp_C = reading_temp * 500.0 / 1024.0;
  //Serial.println(temp_C);
  lcd.write("Temp: ");
  lcd.print(temp_C); 
  lcd.setCursor(10, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1); // 두 번째 행으로 이동
  int reading_light = analogRead(A2);
  float light = reading_light * 5.0 / 1024.0;
  lcd.write("Light: ");
  lcd.print(light);
  delay(1000);
}
