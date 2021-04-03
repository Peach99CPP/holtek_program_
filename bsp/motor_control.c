//
// Created by peachRJ on 2021/4/3.
//

#include <stdlib.h>
#include "motor_control.h"
#include "tracker.h"
#include "pid_.h"

#define speed_k 0.3
motor_speed motor[2], global_;

void speed_set(int x, int y) {
    global_.vx = x;
    global_.vy = y;
}


void set_direct(int motor_number, int dir)//前为正 向后为负
{
    if (motor_number == 1) {
        if (dir == 1) {
            HAL_GPIO_WritePin(motor1_p_GPIO_Port, motor1_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(motor1_n_GPIO_Port, motor1_n_Pin, GPIO_PIN_RESET);
        }
        else {
            HAL_GPIO_WritePin(motor1_p_GPIO_Port, motor1_p_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(motor1_n_GPIO_Port, motor1_n_Pin, GPIO_PIN_SET);
        }
    }
    else {
        if (dir == 1) {
            HAL_GPIO_WritePin(motor2_p_GPIO_Port, motor2_p_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(motor2_n_GPIO_Port, motor2_n_Pin, GPIO_PIN_RESET);
        }
        else {
            HAL_GPIO_WritePin(motor2_p_GPIO_Port, motor2_p_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(motor2_n_GPIO_Port, motor2_n_Pin, GPIO_PIN_SET);
        }
    }

}

void motor_set_pwm(int number, int output) {
    if (number == 1) {
        if (output > 0) set_direct(number, 1);
        else set_direct(number, -1);
        TIM1->CCR1 = abs(output);
    }
    else {//opposite
        if (output > 0) set_direct(number, -1);//向前
        else set_direct(number, 1);
        TIM1->CCR2 = abs(output);
    }
}

short read_encoder(int motor_num) {
    if (motor_num == 1) {
        return (short) (TIM2->CNT);
    }
    else return (short) (-TIM3->CNT);
}

void speed_cal(void) {//left 0 right 1
    motor[0].target = global_.vx - global_.vy * speed_k + get_tracker_num();
    motor[1].target = (global_.vx + global_.vy * speed_k - get_tracker_num());
    motor_set_pwm(1, PID_cal(&motor_[0], read_encoder(1), motor[0].target));
    motor_set_pwm(1, PID_cal(&motor_[1], read_encoder(2), motor[1].target));
}

void motor_stop() {
    speed_set(0, 0);
}