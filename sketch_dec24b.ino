#include <SoftwareSerial.h>
#include <Servo.h>
#include "MyClass.h"
#include "Arduino.h"

char a;
int OFF = 1;
MotorControl motor(6, 12, 11, 13, 3, 5);

SoftwareSerial bluTee(8,9);
Servo myservo;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluTee.begin(9600);
  pinMode(2,INPUT);
  pinMode(7,INPUT);
  pinMode(4,INPUT);
  motor.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  int right = digitalRead(7);
  int left = digitalRead(2);
  int middle = digitalRead(4);
 //Serial.println(right*left*middle);
  //1碰線
  if(OFF){
    if(right*left*middle){
      motor.moveStop();
      OFF = 0;
    }else if(left){
      motor.moveLeft();
    }else if(right){
      motor.moveRight();
    }else{
      motor.moveForward();
    }
    delay(50);
    motor.moveStop();
    delay(100);
  }
  if(Serial.available()){
    a = Serial.read();
    bluTee.print(a);
  } 
  if(Serial.available()){
    a = bluTee.read();
    Serial.println(a);
  }
  if(right){
    if(Serial.read()=='f'){
      motor.moveForward();
    }else if(Serial.read()=='r'){
      motor.moveRight();
    }else if(Serial.read()=='l'){
      motor.moveLeft();
    }
    delay(40);
  }
}


 
