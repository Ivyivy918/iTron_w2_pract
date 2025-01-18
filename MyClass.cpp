#include "Arduino.h"
#include "MyClass.h"

void MotorControl::moveStop(){
  digitalWrite(left_IN1, HIGH);
  digitalWrite(left_IN2, LOW);
  analogWrite(left_pwm, 0);
  digitalWrite(right_IN3, HIGH);
  digitalWrite(right_IN4, LOW);
  analogWrite(right_pwm, 0);
}
void MotorControl::moveForward(){
  digitalWrite(left_IN1, HIGH);
  digitalWrite(left_IN2, LOW);
  analogWrite(left_pwm, 90);
  digitalWrite(right_IN3, LOW);
  digitalWrite(right_IN4, HIGH);
  analogWrite(right_pwm, 120);
}
void MotorControl::moveLeft(){
  digitalWrite(left_IN1, HIGH);
  digitalWrite(left_IN2, LOW);
  analogWrite(left_pwm, 255);
  digitalWrite(right_IN3, LOW);
  digitalWrite(right_IN4, LOW);
  analogWrite(right_pwm, 0);
}
void MotorControl::moveRight(){
  digitalWrite(left_IN1, LOW);
  digitalWrite(left_IN2, LOW);
  analogWrite(left_pwm, 0);
  digitalWrite(right_IN3, LOW);
  digitalWrite(right_IN4, HIGH);
  analogWrite(right_pwm, 255);
}
