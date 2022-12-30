byte patterns[] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};

int digit_select_pin[] = {66, 67, 68, 69}; // 자릿수 선택 핀

int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};

int button = 14; 

int SEGMENT_DELAY = 5; 

unsigned long time_previous, time_current;

int count = 0;

int state = 0;

int button_count = 0; //버튼 누른 횟수

boolean state_previous = false; 

boolean state_current; 


void setup() {

  Serial.begin(9600);

  pinMode(button,INPUT);

  for (int i = 0; i < 4; i++) { 

    pinMode(digit_select_pin[i], OUTPUT);

  }

  for (int i = 0; i < 8; i++) { 

    pinMode(segment_pin[i], OUTPUT);

  }

}


void show_digit(int pos, int number) { // (위치, 출력할 숫자)

  for (int i = 0; i < 4; i++) {

    if (i + 1 == pos) // 해당 자릿수의 선택 핀만 LOW로 설정

      digitalWrite(digit_select_pin[i], LOW);

    else // 나머지 자리는 HIGH로 설정

      digitalWrite(digit_select_pin[i], HIGH);

  }

  for (int i = 0; i < 8; i++) {

    boolean on_off = bitRead(patterns[number], 7 - i);

    digitalWrite(segment_pin[i], on_off);

  }

}


// 4자리 7세그먼트 표시 장치에 3자리 숫자를 표시하는 함수

void show_3_digit(int number) {

  int hundreads = number / 100; // 백의 자리

  number = number % 100;

  int tens = number / 10; // 십의 자리

  int ones = number % 10; // 일의 자리

  show_digit(2, hundreads);

  delay(SEGMENT_DELAY);

  show_digit(3, tens);

  delay(SEGMENT_DELAY);

  show_digit(4, ones);

  delay(SEGMENT_DELAY);

}


void loop() {

  time_current = millis();
  
  state_current = digitalRead(button); // 버튼 상태 읽기

  if (state_current) { //버튼을 누른 경우

    if (state_previous == false ) { // 이전 상태와 비교

       button_count++; // 버튼 횟수 증가

      state_previous = true;

    }

  }

  else {

    state_previous = false;

  }

  if ((time_current - time_previous) >= 1000) { // 1초 경과

    time_previous = time_current;

    if (state==0) {

      count++; // 표시되는 숫자 1만큼 증가

    }

    if (state==1) { ///하향카운트

      count--;

    }

    if ((button_count)%2==1){ ///버튼을 눌러서 하향카운트로 변환

      state = 1;

    }

    if ((button_count)%2==0) { ///버튼을 눌러서 상향카운트로 변환

      state = 0;

    }

    if (count+1 == 1001) { //999가 되었을시,하향카운트로 변환

      count = 0;

    }

    if (count+1 == 000) { ///000이 되었을시, 상향카운트로 변환

      count = 999;

    }

  }

  show_3_digit(count);

}
