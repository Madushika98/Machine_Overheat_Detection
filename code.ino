#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11


DHT sltc(DHTPIN, DHTTYPE);
const int ledPin=13;
int piezoPin=11;

void setup() {
Serial.begin(9600);
pinMode(ledPin,OUTPUT);
pinMode(piezoPin,OUTPUT);
delay(5000);
Serial.println("DHT11 test!");

sltc.begin();
}

void loop() {

delay(1000);



float t = sltc.readTemperature();


Serial.print(t);
  if(t>30){
    digitalWrite(ledPin,HIGH);
    digitalWrite(piezoPin,HIGH);
    {tone(9,3047,400);
    delay(1000);
    noTone(8);
    delay(100);
    }
    delay(1000);
    Serial.print("ON T=");
  }
  else{digitalWrite(piezoPin,LOW);
  digitalWrite(ledPin,LOW);
  Serial.print("OFF,T=");
}

}
