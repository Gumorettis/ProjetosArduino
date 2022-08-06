#define pinoSensor 8
#define pinoSensor2 7
#define motorA1 6
#define motorA2 5
#define motorB1 10
#define motorB2 9

void setup() {
  // put your setup code here, to run once:

  pinMode(pinoSensor,INPUT);
  pinMode(pinoSensor2, INPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  bool estadoSensor1 = digitalRead(pinoSensor); //LENDO O QUE MEU PINO ESTÁ CAPTANDO
  bool estadoSensor2 = digitalRead(pinoSensor2);
  
  if(estadoSensor1 == 1 && estadoSensor2 == 1){
    Serial.println("PRETO ou nada");
    delay(300);
    digitalWrite(motorA1, LOW);
    digitalWrite(motorB1, LOW);    
    Serial.println(estadoSensor1);
    Serial.println(estadoSensor2);
    delay(300);
  }
  else if(estadoSensor1 == 0 && estadoSensor2 == 0){
    Serial.println("BRANCO OU DIFERENTE DE PRETO");  
    delay(300);
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorB1, HIGH);
    Serial.println(estadoSensor1);
    Serial.println(estadoSensor2);
    delay(300);
  }
  
}
