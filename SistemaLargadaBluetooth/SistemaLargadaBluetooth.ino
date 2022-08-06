#define led 13
#define motorA 4
#define motorB 

#include <SoftwareSerial.h>
SoftwareSerial btSerial(8, 9); // RX, TX

void setup() {
  
  pinMode(led, OUTPUT);
  pinMode(motorA, OUTPUT);
  
  btSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {

  while (btSerial.available()) {
    
    int comandoRec = btSerial.read();
    Serial.println(comandoRec);

    if (comandoRec == 49) {

      digitalWrite(led, HIGH);
      digitalWrite(motorA, HIGH);
      digitalWrite(motorB, HIGH);
      
      Serial.println("MOTORES LIGADOS");
      delay(200);
    }

    if (comandoRec == 50) {

      digitalWrite(motorA, LOW);
      digitalWrite(motorB, LOW);
      Serial.println("MOTORES DESLIGADOS");
      delay(200);
    }
  }
}
