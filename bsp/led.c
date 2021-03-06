//
// Created by peachRJ on 2021/4/3.
//

#include "led.h"
#include "my_led.h"

void Led_Control(int is_red, int is_green, int is_blue) {//1就是开 0就是关，以此来控制RGB灯的颜色
    if (is_red) HAL_GPIO_WritePin(red_GPIO_Port, red_Pin, GPIO_PIN_RESET);
    else HAL_GPIO_WritePin(red_GPIO_Port, red_Pin, GPIO_PIN_SET);

    if (is_green) HAL_GPIO_WritePin(green_GPIO_Port, green_Pin, GPIO_PIN_RESET);
    else HAL_GPIO_WritePin(green_GPIO_Port, green_Pin, GPIO_PIN_SET);

    if (is_blue) HAL_GPIO_WritePin(blue_GPIO_Port, blue_Pin, GPIO_PIN_RESET);
    else HAL_GPIO_WritePin(blue_GPIO_Port, blue_Pin, GPIO_PIN_SET);
}

