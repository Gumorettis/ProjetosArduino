int aux = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  
  if(aux == 1){
    analogWrite(3,1001);
  }
  else{
    analogWrite(11,0);  
  }

  delay(1000);
  Serial.println(aux);
  delay(1000);
}
