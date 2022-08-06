#define pinoSensor 8
#define pinoSentido1MotorA 3
#define pinoSentido2MotorA 4

void setup() {
  
  // put your setup code here, to run once:
  pinMode(pinoSensor,INPUT);
  pinMode(pinoSentido1MotorA, OUTPUT);
  pinMode(pinoSentido2MotorA, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {

  bool estadoSensor1 = digitalRead(pinoSensor);

  if(estadoSensor1){
    digitalWrite(pinoSentido1MotorA, LOW);
    digitalWrite(pinoSentido2MotorA, HIGH);
    Serial.println("PRETO OU OUTRA COR");
    delay(500);
    Serial.println(estadoSensor1);
    delay(500);
  }
  else{
    digitalWrite(pinoSentido2MotorA, LOW);
    digitalWrite(pinoSentido1MotorA, HIGH);
    Serial.println("BRANCO OU DIFERENTE DE PRETO");
    
    delay(500);
    Serial.println(estadoSensor1);
    delay(500);
  }
    
}
