int relay = 8;

void setup() {

  pinMode(relay, OUTPUT);

}

void loop() {
  digitalWrite(relay, HIGH);
  delay(6000);
  digitalWrite(relay, LOW);
  delay(2000);

}
