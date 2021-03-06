//
// Created by peachRJ on 2021/4/3.
//

#ifndef HOLTEK_MOTOR_CONTROL_H
#define HOLTEK_MOTOR_CONTROL_H

#include <stdbool.h>
#include "main.h"


typedef struct{
    int vx,vy;
    float target;
}motor_speed;
void speed_set(int x,int y);
void set_direct(int motor_number,int dir);
extern motor_speed  motor[2],global_;
void motor_set_pwm(int number,int output);
short read_encoder(int motor_num);
void speed_cal(void);
void motor_stop();
int get_avd(void);
void set_avd(bool state);
void turn(void);
extern bool avd_on;
void speed_run(int speed);
void start_pro(void);
int Get_MV_pid(void);
#endif //HOLTEK_MOTOR_CONTROL_H
