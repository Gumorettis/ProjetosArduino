void setup() {
  // put your setup code here, to run once:

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(8,LOW);
  delay(1000);
  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(9,LOW);
  delay(1000);
  digitalWrite(10, HIGH);
  delay(2000);
  digitalWrite(10,LOW);
  delay(1000);
}
