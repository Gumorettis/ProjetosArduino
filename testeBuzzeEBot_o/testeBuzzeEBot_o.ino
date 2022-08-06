void setup() {

  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT); 
  pinMode(7, INPUT);
  pinMode(6, OUTPUT); 

}

void loop() {

  int btn = digitalRead(7); 

  
  if( btn == 1){

    digitalWrite(12, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, 0);
  }
  else{
    digitalWrite(12, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH); 
  }

  
}
