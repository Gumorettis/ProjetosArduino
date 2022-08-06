void setup() {
  
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop() {
  
    digitalWrite(13, HIGH);
    delay(4000);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(5000);
    digitalWrite(12,LOW);
    digitalWrite(7, 1);
    delay(7000);
    digitalWrite(7, 0); 
}
