#include <Servo.h> 
Servo s;  // cria o objeto Servo


// Pino analgico do potenciometro
int potpin = A0;

// Variavel que armazena o valor lido do potenciometro
int val;     

void setup() 
{ 
  // Define que o servo esta ligado a porta 6
  s.attach(8);

  // inicia na posição 0
  s.write(100);
    
} 

void loop() 
{ 
  // Le o valor do potenciometro (valores entre 0 e 1023) 
  val = analogRead(potpin);            

  // Converte o valor pra ser usado no servo (valores entre 0 e 180 graus) 
  val = map(val, 0, 1023, 0, 179);     

  // Move o eixo do servo, de acordo com o angulo
  s.write(val);                  

  // Aguarda o servo atingir a posição
  delay(10);                           
}
