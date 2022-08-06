#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pinLDR =  A0;
int valorLido;
int pinPot = A5;
int valorPot = 0;

float luminosidade = 0;
//const int valorLido = 0;

void setup() {

  Serial.begin(9600);
  pinMode(pinLDR, INPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(pinPot, INPUT);
  lcd.begin(16, 2);

}

void loop() {

  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);

  valorPot = analogRead(pinPot);
  luminosidade = map(valorPot, 0, 1023, 0, 255); // Remapeia um número de um intervalo para outro, convertendo de 1023 lido para 255 variando

  valorLido = analogRead(pinLDR); // lê o valor que está vindo do sensor no pino A0
  Serial.println("Valor Lido: ");
  Serial.println(valorLido);     //printa o valor da leitura que será entre 0 a 1023
  delay(300);

  //Envia o texto entre aspas para o LCD
  // lcd.print("");
  //lcd.setCursor(3, 1);
  //lcd.print(" LCD 16x2");
  //delay(5000);

  //Rolagem para a esquerda depois de 5 segundos
  for (int posicao = 0; posicao < 3; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }

  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }

  if (valorLido >= 800) {
    digitalWrite(8, 0);
    digitalWrite(10, HIGH);
    analogWrite(10, luminosidade);

    //Envia o texto entre aspas para o LCD
    lcd.print("");
    lcd.setCursor(3, 2);
    lcd.print(" Luminosidade Baixa! ");
    
  }
  else {
    digitalWrite(8, 1);
    digitalWrite(10, LOW);

    //Envia o texto entre aspas para o LCD
    lcd.print("");
    lcd.setCursor(3, 2);
    lcd.print(" Luminosidade Alta! ");

  }

}
