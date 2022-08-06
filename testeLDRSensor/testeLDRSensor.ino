const int pinLDR =  A0;
const int ledPin = 12;
int valorLido; 
int pinPot = A5;
int valorPot = 0;

float luminosidade = 0;
//const int valorLido = 0;

void setup() {

  Serial.begin(9600);
  pinMode(pinLDR, INPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(pinPot, INPUT);
   
}

void loop() {

  valorPot = analogRead(pinPot);
  luminosidade = map(valorPot, 0, 1023, 0, 255); // Remapeia um número de um intervalo para outro, convertendo de 1023 lido para 255 variando
  
  valorLido = analogRead(pinLDR); // lê o valor que está vindo do sensor no pino A0
  Serial.println("Valor Lido: ");
  Serial.println(valorLido);     //printa o valor da leitura que será entre 0 a 1023 
  delay(300);

  if(valorLido >= 800){
    digitalWrite(12, 0);
    digitalWrite(10, HIGH);
    analogWrite(10, luminosidade);
  }
  else{
    digitalWrite(12, 1);
    digitalWrite(10, LOW);
  }

}
