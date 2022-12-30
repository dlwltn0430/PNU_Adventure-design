int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;
int button_pin = 14;
int press_button = 0;

void setup() {
  pinMode(Enable1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  digitalWrite(Enable1, HIGH); //모터 제어 가능 상태
  pinMode(button_pin, INPUT);
  analogWrite(PWM1, 0);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button_pin)) {
    press_button = (press_button + 1) % 3;
    if (press_button == 0) analogWrite(PWM1, 0);
    if (press_button == 1) analogWrite(PWM1, 127);
    if (press_button == 2) analogWrite(PWM1, 255);
    delay(1000); 
  }
}
