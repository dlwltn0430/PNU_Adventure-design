int pins[]= {2,3,4,5}; 
int pattern, shift, index;

void setup() {
  Serial.begin(9600);
  for (int i=0; i<4; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
}

void loop() {
  for (index=0; index<6; index++) {
    pattern=1;
    
  if (index<4) shift = index;
  else shift = 6 - index;
  
  for (int i=0; i<shift; i++)
    pattern = (pattern << 1) | 0x01;  

  if(pattern==0b0001){
    digitalWrite(pins[0],HIGH);
    digitalWrite(pins[1],LOW);
    digitalWrite(pins[2],LOW);
    digitalWrite(pins[3],LOW);
    }

  if(pattern==0b0011){
    digitalWrite(pins[0],HIGH);
    digitalWrite(pins[1],HIGH);
    digitalWrite(pins[2],LOW);
    digitalWrite(pins[3],LOW);
    }

  if(pattern==0b0111){
    digitalWrite(pins[0],HIGH);
    digitalWrite(pins[1],HIGH);
    digitalWrite(pins[2],HIGH);
    digitalWrite(pins[3],LOW);
    }

  if(pattern==0b1111){
    digitalWrite(pins[0],HIGH);
    digitalWrite(pins[1],HIGH);
    digitalWrite(pins[2],HIGH);
    digitalWrite(pins[3],HIGH);
    }

  delay(1000);
  }
}
