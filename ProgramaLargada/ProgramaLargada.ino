#define motorA 5
#define motorB 4
#define led 13

#include <SoftwareSerial.h>
SoftwareSerial btSerial(8, 9); //TX, RX

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);//inicializei o monitor serial
  btSerial.begin(9600); //inicializei o módulo

}

void loop() {

  while (btSerial.available()) {

    int comandoRecebido = btSerial.read();
    Serial.println(comandoRecebido);
    delay(100);

    if (comandoRecebido == 49) {

      digitalWrite(motorA, HIGH);
      digitalWrite(motorB, HIGH);
      
      Serial.println("MOTORES LIGADOS");
      delay(200);
    }

    if (comandoRecebido == 50) {

      digitalWrite(motorA, LOW);
      digitalWrite(motorB, LOW);
      
      Serial.println("MOTORES DESLIGADOS");
      delay(200);
    }
  }
}
