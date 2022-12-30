void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter 2 Integers to add");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while (Serial.available()) {
    int num1 = Serial.parseInt();
    int num2 = Serial.parseInt();
    int sum = num1 + num2;
    
    Serial.print(num1);
    Serial.print(" + ");
    Serial.print(num2);
    Serial.print(" = ");
    Serial.println(sum);
    Serial.println("Enter 2 Integers to add");
  }
}
