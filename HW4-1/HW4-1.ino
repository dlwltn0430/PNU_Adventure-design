void setup() {
  Serial.begin(9600);
}

void loop() {
  int state = 1, i = 0;
  char buffer[128];
  String str[5];

  while (true) {
    while(i<5) {
    if (state == 1) {
      Serial.print("Enter the ");
      Serial.print(i+1);
      Serial.print("th Word -->");
     state = 2;
  }

  while (Serial.available()) {
    int len = Serial.readBytesUntil('\n', buffer, 127);
    if (len>0) {
      buffer[len] = '\0';
      str[i] = String (buffer);
      Serial.println(str[i]);
      i += 1;
      state = 1;
      break;
    }
  }
    }
    if (i==5) break;
  }

  //문자열 정렬
  for (int j=0; j<4; j++) {
    for (int k=j+1; k<5; k++) {
      int compare = str[j].compareTo(str[k]);
      if (compare>0) { //오름차순으로 정렬
        String temp = str[j];
        str[j] = str[k];
        str[k] = temp;
      }
    }
  }
  
  Serial.println("After Sorting");
  for (int l=0; l<=4; l++) {
    Serial.println(str[l]);
  }
 }
