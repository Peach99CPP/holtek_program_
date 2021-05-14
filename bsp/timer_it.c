//
// Created by peachRJ on 2021/4/3.
//

#include <tim.h>
#include <math.h>
#include "timer_it.h"
#include "motor_control.h"
#include "retarget.h"
#include "pid_.h"

#define MAX_TIME 2147483640
volatile int sys_time = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim == (&htim6)) {
        sys_time++;
        if (sys_time == 50) {
            speed_cal();
//            HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
            sys_time = 0;
        }
        if (sys_time > (MAX_TIME))
            sys_time = 0;
    }

}

volatile int *get_sys_ptr() {
    return &sys_time;
}
void Init_TIMS(void){//对定时器进行初始化
    //开启定时器
    HAL_TIM_Base_Start(&htim1);
    HAL_TIM_Base_Start(&htim2);
    HAL_TIM_Base_Start(&htim3);
    HAL_TIM_Base_Start_IT(&htim6);
    //使能定时器1 2的PWM输出口
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
    //开启定时器2 3的编码器模式
    HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
}
