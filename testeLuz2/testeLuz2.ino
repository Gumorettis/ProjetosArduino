void setup() {

  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
   
}

void loop() {

  digitalWrite(4, 1);
  delay(500);
  digitalWrite(4,0);
  digitalWrite(8, 1);
  delay(500);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  delay(500);
  digitalWrite(9, 0);
  
}
