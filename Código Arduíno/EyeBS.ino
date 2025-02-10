#include "Ultrasonic.h"

int trigger = 10, echo = 9;
int buzzer = 11; 
int mvm = 3;
int blue = A3;
int green = A4;
int red = A5;
float distancia = 0;
HC_SR04 sensor1(trigger, echo);

void setup() 
{ 
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT);  
  pinMode(buzzer, OUTPUT);
  pinMode(mvm, OUTPUT);
  Serial.begin(9600);
} 

void loop() 
{ 
  distancia = sensor1.distance();
  
  if (distancia <= 60) {
    tone(buzzer, 2000, 500);
    analogWrite(mvm, 255);
    analogWrite(blue, 255);
    analogWrite(green, 0);
    
  }
  else if (distancia > 60 && distancia <= 110) { 
    tone(buzzer, 2000, 250);  
    analogWrite(mvm, 0); 
    analogWrite(blue, 255);
    analogWrite(green, 255);
  }
  else if (distancia > 110) { 
    noTone(buzzer);
    analogWrite(mvm, 0); 
    analogWrite(blue, 0);
    analogWrite(green, 255); 
  }
  
  Serial.print("Distancia em centimentros: "); 
  Serial.println(distancia);
  delay(300);
}

