#define pinoSensor 8

void setup() {
  // put your setup code here, to run once:

  pinMode(pinoSensor,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  bool estadoSensor1 = digitalRead(pinoSensor); //LENDO O QUE MEU PINO ESTÁ CAPTANDO

  if(estadoSensor1){
    Serial.println("PRETO ou nada");
    delay(300);
    Serial.println(estadoSensor1);
    delay(300);
  }
  else{
    Serial.println("BRANCO OU DIFERENTE DE PRETO");  
    delay(300);
    Serial.println(estadoSensor1);
    delay(300);
  }
  
}
