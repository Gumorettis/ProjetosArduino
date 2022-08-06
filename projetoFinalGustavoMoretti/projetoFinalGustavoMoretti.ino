
// Autor: Gustavo Moretti
// Projeto: Medindo Umidade e temperatura e imprimindo os valores em um LCD 16x2 

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h> 

#define DHTTYPE DHT22 
#define DHTPIN 7

DHT dht(DHTPIN, DHTTYPE);

float temp = 0;
float u = 0; 

byte custom[8] = {
  0b00111,          
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{  
  Serial.begin(9600);   
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  analogReference(INTERNAL);  
  lcd.init();           
  lcd.backlight(); 
  lcd.createChar(5, custom); // Cria caractere definindo-o como o byte 5
  
  dht.begin(); //inicia o sensor dht
}  

void loop()
{   
  
  delay(1500); // delay das medições

  u = dht.readHumidity(); //lê a humidade
  temp = dht.readTemperature(); // lê a temperatura

  //verifica se o sensor está funcionando corretamente
  if (isnan(u) || isnan(temp))
  {
    Serial.println("Falha na leitura do sensor DHT !!!");
    return;
  }

  if(u <= 30){
    digitalWrite(8, 1);
  }
  else{
    digitalWrite(8, 0);
  }

  if(temp >= 30){
    digitalWrite(12, 1);  
  }
  else{
    digitalWrite(12, 0);  
  }
  
  lcd.print("  Temp.:");
  lcd.print(temp);   
  lcd.print("C"); 
  lcd.home(); // Seta o cursor para o inicio caracter 0, na linha 0
  lcd.print("->");
  
  lcd.setCursor(0,1);
  lcd.print("  Umid.: ");
  lcd.print(u);
  lcd.print(" %");   
  lcd.setCursor(0,1);
  lcd.print("->");  
  lcd.setCursor(14,0); 
  lcd.write(5); // Imprime o byte 5(nosso caracter custom)

  
  delay(2000); 
  lcd.clear(); //Limpa a tela do LCD
}
