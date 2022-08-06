float RGB1[3];
float RGB2[3];
float INC[3];
int red, green, blue;
int RedPin = 8;
int GreenPin = 12;
int BluePin = 13;

void setup() {
  
pinMode(8,OUTPUT); //R
pinMode(12,OUTPUT); //G
pinMode(13,OUTPUT); //B

}

void loop() {
  
digitalWrite(8,HIGH);
delay(1000);
digitalWrite(8,LOW);

digitalWrite(12,HIGH);
delay(1000);
digitalWrite(12,LOW);

digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);

delay(1000);

}
