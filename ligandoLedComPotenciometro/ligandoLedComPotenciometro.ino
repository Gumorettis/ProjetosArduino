//Variaveis
int valorPot; //Valor do potenciometro
int leds; //variavel dos LEDs

void setup() {
  
  //Declarando como entrada as portas dos LEDs
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  

  //Declarando comno saida a porta do potenciometro
  pinMode(A0, INPUT);
}

void loop() {

 valorPot = analogRead(A0); //Guarda a leitura da porta do potenciometro (A0)

 leds = map(valorPot, 0, 1023, 7, 13); //Mapeia a variavel valorPot, e guarda o mapeamento em leds
                              

//Desliga todos os LEDs
 digitalWrite(13, LOW);
 digitalWrite(10, LOW);
 digitalWrite(7, LOW);
 

 //Liga somente o LED que está na variavel leds, que irá variar de 7 a 13 conforme a leitura do potenciometro
 digitalWrite(leds, 1);
}
