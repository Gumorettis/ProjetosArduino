int btn;

void setup() {
  // put your setup code here, to run once:

  pinMode(12,OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(3, OUTPUT);
  
}

void loop() {

  btn = digitalRead(8); // o que está chegando no pino 7

  if( btn==0 ){
    
    digitalWrite(7, LOW);
    digitalWrite(12,LOW);
    digitalWrite(13, LOW);
    digitalWrite(3, LOW);
    
  }
  else {
    
    digitalWrite(7, HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(3, HIGH);
    
  }

  delay(5); 
}
