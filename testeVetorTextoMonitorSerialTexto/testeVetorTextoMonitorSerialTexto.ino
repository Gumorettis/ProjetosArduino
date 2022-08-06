String vetor [4] = {"Ana", "Julia", "Bruno", "Lucas"}; 
int i, j, aux;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (i = 0; i < 3; i++) {

    for (j = 0; j < 4; j++) {
      
      Serial.println(vetor[j]);
      delay(3000);
    }
    
    Serial.println("_____________________________________________ Fim do Vetor!");
    delay(9000);
  }

}
