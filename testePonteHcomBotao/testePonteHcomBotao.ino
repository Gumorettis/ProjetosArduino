#define pinoA 5 // definindo o pino do push button 

// definindo os pinos responsaveis pelo sentido do motor 
#define pinoSentido1MotorA 3
#define pinoSentido2MotorA 2
#define velocidadeMotor 6

int velocidade = 0;

byte estadoA = 0; // variavel auxiliar para ajudar a controlar o estado inicial do botao 

//variaveis abaixo para controlar o estado do botão (acionado ou não)
bool estadoBotaoA = true;
bool estadoAntBotaoA = true;
unsigned long delayBotaoA; 


void setup() {

  pinMode(pinoA, INPUT_PULLUP); // declaro o tipo de pino o do motor 

  //definindo o tipo de pino dos sentidos (que controlam a ponte H) 
  pinMode(pinoSentido1MotorA,OUTPUT);
  pinMode(pinoSentido2MotorA,OUTPUT);
  analogWrite(velocidadeMotor, velocidade);
}

void loop() {

  // fazendo a verificação do que esta sendo lido no botao especificado
  estadoBotaoA = digitalRead(pinoA);
  
  
  //verificando se houve mudança no estado do botão (se apertou ou não) 
  if(!estadoBotaoA && estadoAntBotaoA){
    if((millis() - delayBotaoA) > 20){
      estadoA++;
    
    if(estadoA > 2){
      estadoA = 0; 
        }
        delayBotaoA = millis();
    }
  }
    else if(estadoBotaoA != estadoAntBotaoA){
    delayBotaoA = millis();
  }

  estadoAntBotaoA = estadoBotaoA; //passando o ultimo estado do botao para variavel

   //configuração da ponte H abaixo
   if(estadoA == 0){
    digitalWrite(pinoSentido1MotorA, LOW);
    digitalWrite(pinoSentido2MotorA, LOW);

    digitalWrite(11, LOW);
    
   }
   else{

        if(estadoA == 1){
          digitalWrite(pinoSentido1MotorA, LOW);
          digitalWrite(pinoSentido2MotorA, HIGH);
        }
        else{ // ou seja se o estado for == 2 
          velocidade = 2000; 
          analogWrite(velocidadeMotor, velocidade);
          digitalWrite(pinoSentido1MotorA, HIGH);
          digitalWrite(pinoSentido2MotorA, LOW);
        }
   }
}
