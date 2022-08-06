int ThermistorPin = A0;  //pino sensor A0 
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT); 

s.attach(pinoServo); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  s.write(100); //INICIA O MOTOR NA POSIÇÃO 0º
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));  //calculo base da temperatura
  Tc = T - 273.15; // calculo temperatura em C
  Tf = (Tc * 9.0)/ 5.0 + 32.0; // calculo temperatura em F

  if(Tc >= 33){
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
  }
  
  else if(Tc <= 30){
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
  
  Serial.print("Temperatura: "); 
  //Serial.print(Tf);
  //Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");   

  delay(500);
}
