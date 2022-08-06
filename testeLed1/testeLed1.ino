void setup() {
  // put your setup code here, to run once:

  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(13, HIGH);
  delay(5000);
  digitalWrite(13, LOW);

  digitalWrite(12, HIGH);
  delay(1400);
  digitalWrite(12, LOW);

  digitalWrite(8, HIGH);
  delay(6000);
  digitalWrite(8, LOW);

  delay(500);
}
