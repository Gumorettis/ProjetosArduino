#define led 13
#define rele 7

#include <SoftwareSerial.h>
SoftwareSerial btSerial(8, 9); // RX, TX

void setup() {
  
  pinMode(led, OUTPUT);
  pinMode(rele, OUTPUT);
  
  btSerial.begin(9600);
  digitalWrite(rele, 1);
  Serial.begin(9600);
}

void loop() {

  while (btSerial.available()) {
    
    int comandoRec = btSerial.read();
    Serial.println(comandoRec);

    if (comandoRec == 49) {
      digitalWrite(led, HIGH);
      digitalWrite(rele, 1);
    }

    if (comandoRec == 50) {
      
      digitalWrite(led, LOW);
      digitalWrite(rele, 0);
    }
  }
}
