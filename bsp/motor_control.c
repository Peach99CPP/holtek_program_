//
// Created by peachRJ on 2021/4/3.
//

#include <stdlib.h>
#include "motor_control.h"
#include "tracker.h"
#include "pid_.h"
#include "bsp_delay.h"
#include "retarget.h"
#define speed_k 0.3
bool avd_on=false;
motor_speed motor[2], global_;

void speed_set(int x, int y) {
    global_.vx = x;
    global_.vy = y;
}

int get_avd(void) {
    if (!avd_on)
        return 0;
    else {
        if (HAL_GPIO_ReadPin(avd_GPIO_Port, avd_Pin) != GPIO_PIN_SET)
            return 0;
        else
            return 1;
    }
}

void set_direct(int motor_number, int dir)//前为正 向后为负
{
    if (motor_number == 1) {
        if (dir == 1) {
            HAL_GPIO_WritePin(motor1_p_GPIO_Port, motor1_p_Pin, GPIO_PIN_RESET), \
            HAL_GPIO_WritePin(motor1_n_GPIO_Port, motor1_n_Pin, GPIO_PIN_SET);

        } else {
            HAL_GPIO_WritePin(motor1_p_GPIO_Port, motor1_p_Pin, GPIO_PIN_SET), \
            HAL_GPIO_WritePin(motor1_n_GPIO_Port, motor1_n_Pin, GPIO_PIN_RESET);
        }
    } else if (motor_number == 0) {

        if (dir == 1) {
            HAL_GPIO_WritePin(motor2_p_GPIO_Port, motor2_p_Pin, GPIO_PIN_SET), \
            HAL_GPIO_WritePin(motor2_n_GPIO_Port, motor2_n_Pin, GPIO_PIN_RESET);
        } else if (dir == -1) {
            HAL_GPIO_WritePin(motor2_p_GPIO_Port, motor2_p_Pin, GPIO_PIN_RESET), \
            HAL_GPIO_WritePin(motor2_n_GPIO_Port, motor2_n_Pin, GPIO_PIN_SET);
        }
    }

}

void motor_set_pwm(int number, int output) {
    if (number == 1) {
        if (output > 0)
            set_direct(1, 1);
        else
            set_direct(1, -1);
        TIM1->CCR1 = abs(output);
    } else if (number == 0) {//左侧
        if (output > 0)
            set_direct(0, 1);//向前
        else
            set_direct(0, -1);
        TIM1->CCR2 = abs(output);
    }
}

short read_encoder(int motor_num) {
    short num = 0;
#define Motor_0_CNT  TIM3->CNT
#define Motor_1_CNT  TIM2->CNT
    if (motor_num == 0) {
        num = (short) -(Motor_0_CNT);
        Motor_0_CNT= 0;
    } else if (motor_num == 1) {
        num = (short) (Motor_1_CNT);
        Motor_1_CNT = 0;
    }
    return num;
}

void speed_cal(void) {//left 0 right 1
    //TODO:调试后删除输出语句
    motor[0].target = global_.vx - global_.vy * speed_k;//+ get_tracker_num();
    motor[1].target = global_.vx - global_.vy * speed_k;
    if (0) {//差速转弯避障
        motor[0].target = -30;
        motor[1].target = 30;
    }
    short read_0=read_encoder(0);
    short read_1=read_encoder(1);
    int out_0=PID_cal(&motor_[0], read_0, motor[0].target),out_1=PID_cal(&motor_[1], read_1, motor[1].target);
    motor_set_pwm(0, out_0);
    motor_set_pwm(1, out_1);

}

void motor_stop() {
    motor_set_pwm(1,0);
    motor_set_pwm(0,0);
}

void turn(void) {
    motor[0].target = 30;
    motor[1].target = 30;
    delay_ms(10000);
    speed_set(0, 0);
}
void speed_run(int speed)
{
    motor_set_pwm(1,speed);
    motor_set_pwm(0,speed);
}