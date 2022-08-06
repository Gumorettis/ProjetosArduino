#define pinoSensor1 7
#define pinoSensor2 8
#define motorA1 6
#define motorB1 10

void setup() {
    pinMode(pinoSensor1, INPUT);
    pinMode(pinoSensor2, INPUT);
    pinMode(motorA1, OUTPUT);
    pinMode(motorB1, OUTPUT);
      
    Serial.begin(9600);
}

void loop() {
      bool estadoSensor1 = 1, estadoSensor2 = 1; 
      
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorA1, HIGH);
      
      delay(1000);

      while(estadoSensor1 == 1 || estadoSensor2 == 1){  
      
      estadoSensor1 = digitalRead(pinoSensor1);
      estadoSensor2 = digitalRead(pinoSensor2);

      Serial.println("Estado do sensor 1: ");
      Serial.println(estadoSensor1);

      delay(2000);

      Serial.println("Estado do sensor 2: ");
      Serial.println(estadoSensor2);
      
      if(estadoSensor1 == 1 && estadoSensor2 == 0){
            
            digitalWrite(motorB1, LOW);
            digitalWrite(motorA1, HIGH);
      }
            
            
      if(estadoSensor1 == 0 && estadoSensor2 == 1){
            
            digitalWrite(motorA1, LOW);
            digitalWrite(motorB1, HIGH);
      }
      
            
      
    }
    
            digitalWrite(motorA1, LOW);
            digitalWrite(motorB1, LOW);
            Serial.println("MOTORES DESLIGADOS "); 
            
}
