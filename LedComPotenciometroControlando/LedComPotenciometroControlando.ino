int pinoPot = A5; 
int valorPot = 0; 
float luminosidade = 0; 

void setup() {
  // put your setup code here, to run once:

  pinMode(10, OUTPUT);
  pinMode(pinoPot, INPUT);
  
}

void loop() {
  valorPot = analogRead(pinoPot);
  luminosidade = map(valorPot, 0, 1023, 0, 255); // Remapeia uma variavel para trabalhar dentro de um intervalo baseado no potenciometro

  digitalWrite(10,1);
  analogWrite(10, luminosidade); 
  
}
