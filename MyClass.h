#ifndef MyClass_h
#define MyClass_h
#include "Arduino.h"

class MotorControl {
  private:
    int left_IN1, left_IN2, left_pwm;
    int right_IN3, right_IN4, right_pwm;
    
  public:
    MotorControl(int lIN1, int lIN2, int lPwm, int rIN3, int rIN4, int rPwm)
      : left_IN1(lIN1), left_IN2(lIN2), left_pwm(lPwm), right_IN3(rIN3), right_IN4(rIN4), right_pwm(rPwm) {}
    void setup(){
      pinMode(left_IN1, OUTPUT);
      pinMode(left_IN2, OUTPUT);
      pinMode(left_pwm, OUTPUT);
      pinMode(right_IN3, OUTPUT);
      pinMode(right_IN4, OUTPUT);
      pinMode(right_pwm, OUTPUT);
      }
    void moveStop();
    void moveForward();
    void moveLeft();
    void moveRight();
};

#endif
