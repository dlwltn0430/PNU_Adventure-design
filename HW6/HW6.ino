int pins_LED[] = {2,3}; //LED 연결 핀
unsigned long time_previous[] = {0,0};
unsigned long time_current[] = {0,0};
unsigned long interval[] = {0,0}; 
boolean LED_state[] = {false, false}; 

void setup() {
  pinMode(A0, INPUT);
  for (int i=0; i<2; i++) {
    pinMode(pins_LED[i], OUTPUT);
    digitalWrite(pins_LED[i], LED_state[i]);
    time_previous[i] = millis(); 
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 2; i++) {
    time_current[i] = millis();
    if (time_current[i] - time_previous[i] >= interval[i]) {
      time_previous[i] = time_current[i]; 
      LED_state[i] = !LED_state[i]; 
      digitalWrite(pins_LED[i], LED_state[i]);
    }
    int adc = analogRead(A0); 
    if (i == 0) {
      interval[i] = map(adc, 0, 1023, 1500, 500);
    } else {
      interval[i] = map(adc, 0, 1023, 500, 1500);
    }
  }
}
