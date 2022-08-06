
// Projeto: Medindo Umidade e temperatura com DHT22

#include <Wire.h>
#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN 7


float temp = 0;
float u = 0;
int botao;


void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);

  analogReference(INTERNAL);

  dht.begin(); //inicia o sensor dht
  digitalWrite(8, HIGH);

}

void loop() {

  delay(1000); // delay das medições

  u = dht.readHumidity(); //lê a humidade
  temp = dht.readTemperature(); // lê a temperatura

  //liga a bomba de acordo com a temperatura
  if (temp > 25) {
    digitalWrite(8, LOW);
  }
  else {
    digitalWrite(8, HIGH);
    delay(12000);

  }

  Serial.println(temp);
  botao = analogRead(A0);

  //verifica se o sensor está funcionando corretamente
  if (isnan(u) || isnan(temp)) {
    Serial.println("Falha na leitura do sensor DHT !!!");
    return;
  }

}
