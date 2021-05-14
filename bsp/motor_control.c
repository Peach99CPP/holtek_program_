//
// Created by peachRJ on 2021/4/3.
//

#include <stdlib.h>
#include "motor_control.h"
#include "tracker.h"
#include "pid_.h"
#include "bsp_delay.h"
#include "retarget.h"
#include "bsp_uart.h"
#include "led.h"
#include "my_led.h"

#define speed_k 0.3
bool avd_on=false;
motor_speed motor[2], global_;
short temp_read_1=0,temp_read_0=0;
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

void speed_cal(void) {
    //TODO:调试后删除输出语句
    float tracker_num=get_tracker_num();
    motor[0].target = (int)(global_.vx) - global_.vy * speed_k - 0.1 * mv_pid+tracker_num;//+ get_tracker_num();
    motor[1].target = (int)(global_.vx)+ global_.vy * speed_k + 0.1 * mv_pid-tracker_num;
    motor[0].target*=-4.2f;
    motor[1].target*=-4.2f;
//    if(motor[0].target>0) motor[0].target*=1.2;
    short read_0 = -read_encoder(0);
    short read_1 = -read_encoder(1);
    if(abs(read_0-temp_read_0)>400) read_0=temp_read_0;else temp_read_0=read_0;
    if(abs(read_1-temp_read_1)>400) read_1=temp_read_1; else temp_read_1=read_1;
    int out_0 = (short) PID_cal(&motor_[0], read_0, motor[0].target), out_1 = (short) PID_cal(&motor_[1], read_1,
                                                                                              motor[1].target);
    motor_set_pwm(0, out_0);
    motor_set_pwm(1, out_1);
    printf("%d,%d,%d,%d\r\n",read_0,read_1,(int)motor[0].target,(int)motor[1].target);
    mv_pid = 0;
}

void motor_stop() {
    global_.vx=global_.vy=0;
}

void turn(void) {
    motor[0].target = 30;
    motor[1].target = -30;
    delay_ms(10000);
    speed_set(0, 0);
}
void speed_run(int speed)
{
    motor_set_pwm(1,speed);
    motor_set_pwm(0,speed);
}
void set_avd(bool state)
{
    avd_on=state;
}
void start_pro(void)
{
    speed_set(-60,0);
    delay_ms(5000);
    speed_set(0,0);
    delay_ms(10000);
    Led_Control(0,0,1);
    tracker_set(true);
    speed_set(70,0);
    delay_ms(8000);
    speed_set(0,0);
    tracker_set(false);
    LCD_Show_Expressions(2);
}