//
// Created by peachRJ on 2021/4/3.
//

#ifndef HOLTEK_MOTOR_CONTROL_H
#define HOLTEK_MOTOR_CONTROL_H
#include "main.h"


typedef struct{
    double vx,vy;
    double target;
}motor_speed;
void speed_set(int x,int y);
void set_direct(int motor_number,int dir);
extern motor_speed  motor[2],global_;
void motor_set_pwm(int number,int output);
short raed_encoder(int motor_num);
void speed_cal(void);
void motor_stop();
#endif //HOLTEK_MOTOR_CONTROL_H
