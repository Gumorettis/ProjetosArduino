// Projeto: Medindo Umidade e temperatura com DHT22

#include <Wire.h>
#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN 5
  
DHT dht(DHTPIN, DHTTYPE);

float temp = 0;
float u = 0;
int botao;

#define rele 7

#include <SoftwareSerial.h>
SoftwareSerial btSerial(8, 9); // RX, TX

void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);

  analogReference(INTERNAL);

  dht.begin(); //inicia o sensor dht

  pinMode(rele, OUTPUT);
  btSerial.begin(9600);
  digitalWrite(rele, 1);
 
}

void loop() {

  delay(300); // delay das medições

  u = dht.readHumidity(); //lê a humidade
  temp = dht.readTemperature(); // lê a temperatura

  //liga a bomba de acordo com a temperatura
  if (temp > 25) {
    digitalWrite(8, LOW);
  }
  else {
    digitalWrite(8, HIGH);
    //delay(12000);

  }

  //verifica se o sensor está funcionando corretamente
  if (isnan(u) || isnan(temp)) {
    Serial.println("Falha na leitura do sensor DHT !!!");
    return;
  }

  while (btSerial.available()) {
    
    int comandoRec = btSerial.read();
    Serial.println(comandoRec);

    if (comandoRec == 49) {
      digitalWrite(rele, 1);
    }

    if (comandoRec == 50) {
      
      digitalWrite(rele, 0);
    }
  }

  Serial.println("Temperatura do sensor: ");
  Serial.println(temp); 
  Serial.println("Medida de Umidade: ");
  Serial.println(u); 
  Serial.println("*************************************");
  delay(300);
}
