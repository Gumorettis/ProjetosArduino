int btn;

void setup() {

  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {

  btn = digitalRead(7);

  if (btn == 1) {

    digitalWrite(8, 1);
    delay(200);
    digitalWrite(8, 0);
    delay(200);
   
    digitalWrite(4, 1);
  }

  else {
    digitalWrite(8, 0);
    digitalWrite(4, 0);
  }
  
}
