int vetor [5], i, j, aux;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (i = 0; i < 4; i++) {

    for (j = 0; j < 5; j++) {
      vetor[i] = vetor[i] + 1;
      Serial.println(vetor[i]);
      delay(3000);
    }
    
    Serial.println("_____________________________________________ Fim do Vetor!");
    delay(9000);
  }


}
