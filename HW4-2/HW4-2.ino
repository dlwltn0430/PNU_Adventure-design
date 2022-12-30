int pins_LED[] = {2,3,4,5};
int pins_button = 14;
boolean state_previous = false;
boolean state_current;
int LED_pattern[] = {0b0001,0b0010,0b0100,0b1000};
int i = 0;
int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pins_button, INPUT);
  for (int i=0; i<4; i++) {
    pinMode(pins_LED[i], OUTPUT);
  }
}

void loop() {
  state_current = digitalRead(pins_button);
  
  if (state == 0) {
    if ((state_previous == 0) && (state_current == 1)){
      i = i-2;
      state_previous = 1;
      state = 1;
    }
    
  else{
    if((state_previous = 1) && (state_current == 0)) {
      state_previous = 0;
    }
    if (i==4) i=0;
    if (i<4) {
      for (int j=0; j<4; j++) {
        digitalWrite(pins_LED[j],bitRead(LED_pattern[i],j));
      }
      i = i+1;
      delay(500);
    }
  }
}

  if(state == 1){
    if((state_current==1) && (state_previous==0)){
      i= i+2;
      state_previous = 1;
      state = 0;    
      }
      
      else{
        if((state_current==0)&&(state_previous==1)){
          state_previous = 0;
          }
          
          if(i==-1) i=3;
          if(i>=0){
            for(int j=0;j<4;j++){
              digitalWrite(pins_LED[j],bitRead(LED_pattern[i],j));
            }
            i = i-1;
            delay(500);
            }
            }
  }
}
