#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA
const int pinoServo = 6; //PINO DIGITAL UTILIZADO PELO SERVO  
 
Servo s; //OBJETO DO TIPO SERVO
int pos; //POSIÇÃO DO SERVO


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
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); //calculo base da temperatura
  Tc = T - 273.15; // calculo temperatura em C
  Tf = (Tc * 9.0) / 5.0 + 32.0; // calculo temperatura em F

  if (Tc >= 24) {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);

    for (pos = 0; pos < 180; pos++) { //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 180, INCREMENTA "pos"
      s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
      delay(15); //INTERVALO DE 15 MILISSEGUNDOS
    }
    delay(1000); //INTERVALO DE 1 SEGUNDO
    for (pos = 180; pos >= 0; pos--) { //PARA "pos" IGUAL A 180, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
      s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
      delay(15); //INTERVALO DE 15 MILISSEGUNDOS
    }
  }

  else if (Tc <= 24) {
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
