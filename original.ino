#include <SoftwareSerial.h>
#include <Servo.h>
int left_IN1 = 6;
int left_IN2 = 12;
int left_pwn = 11;
int right_IN3 = 13;
int right_IN4 = 3;
int right_pwn = 5;
char a;

int OFF = 1;

SoftwareSerial bluTee(8,9);
Servo myservo;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluTee.begin(9600);
  pinMode(2,INPUT);
  pinMode(7,INPUT);
  pinMode(4,INPUT);
  pinMode(left_IN1,OUTPUT);
  pinMode(left_IN2,OUTPUT);
  pinMode(left_pwn,OUTPUT);
  pinMode(right_IN3,OUTPUT);
  pinMode(right_IN4,OUTPUT);
  pinMode(right_pwn,OUTPUT);
}

void moveStop(){
  digitalWrite(left_IN1, HIGH);
  digitalWrite(left_IN2, LOW);
  analogWrite(left_pwn, 0);
  digitalWrite(right_IN3, HIGH);
  digitalWrite(right_IN4, LOW);
  analogWrite(right_pwn, 0);
}

void moveForward(){
  digitalWrite(left_IN1, HIGH);
  digitalWrite(left_IN2, LOW);
  analogWrite(left_pwn, 90);
  digitalWrite(right_IN3, LOW);
  digitalWrite(right_IN4, HIGH);
  analogWrite(right_pwn, 120);
}

void moveLeft(){
  digitalWrite(left_IN1, HIGH);
  digitalWrite(left_IN2, LOW);
  analogWrite(left_pwn, 255);
  digitalWrite(right_IN3, LOW);
  digitalWrite(right_IN4, LOW);
  analogWrite(right_pwn, 0);
}

void moveRight(){
  digitalWrite(left_IN1, LOW);
  digitalWrite(left_IN2, LOW);
  analogWrite(left_pwn, 0);
  digitalWrite(right_IN3, LOW);
  digitalWrite(right_IN4, HIGH);
  analogWrite(right_pwn, 255);
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
      moveStop();
      OFF = 0;
    }else if(left){
      moveLeft();
    }else if(right){
      moveRight();
    }else{
      moveForward();
    }
    delay(50);
    moveStop();
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
      moveForward();
    }else if(Serial.read()=='r'){
      moveRight();
    }else if(Serial.read()=='l'){
      moveLeft();
    }
    delay(40);
  }
}


 
