#include<Servo.h>
#include<LiquidCrystal.h>

Servo servo1;
int servo1pin=7;
int trigpin=5;
int echopin=6;
int rledpin=3;
int gledpin=2;
int buzpin=4;
float duration,distance;
int pos=0;

const int rs=13 , en=12 , d4=11, d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);




void setup() {
  // put your setup code here, to run once:
  servo1.attach(servo1pin);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(rledpin,OUTPUT);
  pinMode(gledpin,OUTPUT);
  pinMode(buzpin,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(gledpin,HIGH);
  
   for(pos=0;pos<=150;pos++){
    servo1.write(pos);
    loop1:
    lcd.print("                 ");
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin,LOW);
    duration=pulseIn(echopin,HIGH);
    distance=(duration*0.0343)/2;

    Serial.print("Distance = ");
    Serial.println(distance);

    delay(10);
    while(distance<15){
      digitalWrite(gledpin,LOW);
      digitalWrite(rledpin,HIGH);
      digitalWrite(buzpin,HIGH);
      delay(70);
      digitalWrite(rledpin,LOW);
      digitalWrite(buzpin,LOW);
      delay(70);
      lcd.begin(16,2);
      lcd.print("Warning!!");
      lcd.setCursor(0, 1);
      lcd.print("Object in Range !!");
      
      goto loop1;
    }
    digitalWrite(gledpin,HIGH);
    
   }
   for(pos=150;pos>=0;pos--){
    servo1.write(pos);
    loop2:
    lcd.print("                 ");
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin,LOW);
    duration=pulseIn(echopin,HIGH);
    distance=(duration*0.0343)/2;

    Serial.print("Distance = ");
    Serial.println(distance);

    delay(10);
    while(distance<15){
      digitalWrite(gledpin,LOW);
      digitalWrite(rledpin,HIGH);
      digitalWrite(buzpin,HIGH);
      delay(70);
      digitalWrite(rledpin,LOW);
      digitalWrite(buzpin,LOW);
      delay(70);
      lcd.begin(16,2);
      lcd.print("Warning!!");
      lcd.setCursor(0, 1);
      lcd.print("Object in Range !!");
      
      goto loop2;
    }
    digitalWrite(gledpin,HIGH);
   }
}
