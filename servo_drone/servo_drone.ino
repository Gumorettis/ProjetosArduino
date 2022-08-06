#include <Servo.h>
const int pwm=1100;
const int fecha=2000;
void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(10,fecha);
Serial.println(pwm);
delay(2000);
analogWrite(10,pwm);
Serial.println(fecha);
delay(2000);
}
