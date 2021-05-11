//
// Created by peachRJ on 2021/4/3.
//

#include <usart.h>
#include "bsp_uart.h"
#include "retarget.h"
#include "led.h"
#include "motor_control.h"
#include "tracker.h"
#include "bsp_delay.h"
#include "my_led.h"

#include <string.h>

int uart2_receive_flag, uart3_receive_flag, uart4_receive_flag, uart5_receive_flag,
        uart2_index, uart3_index = 0, uart4_index, uart4_index, uart5_index, mv_pid = 0, animal_inf = 0;
static int temp_flag_4 = 0, temp_flag_2 = 0, temp_flag_3 = 0, temp_flag_5 = 0;
uint8_t uart2_[MAX_SIZE], uart3_[MAX_SIZE], uart4_[MAX_SIZE], uart5_[MAX_SIZE];

void Init_UARTS(void) {//初始化串口
    //全部是接收中断
    __HAL_UART_ENABLE(&huart4);
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
    __HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);
    __HAL_UART_ENABLE_IT(&huart4, UART_IT_RXNE);\

}

void UART_transmit(UART_HandleTypeDef *huart, char ch[])//通过全局printf函数发送数据
{
    RetargetInit(huart);
    printf("%s", ch);
}

void USART2_IRQHandler(void) {
    uint8_t data;
    if (USART2->SR & (1 << 5)) {
        data = USART2->DR;
        if (!uart2_receive_flag) {
            if (temp_flag_2) {
                if (data == 0X43) {
                    uart2_receive_flag = 1;
                    temp_flag_2 = 0;
                }
                else { uart2_[uart2_index++] = data; }
                if (uart2_index == MAX_SIZE) {
                    temp_flag_2 = 0;
                    memset(&uart2_, 0, sizeof(uart2_));
                }
            }
            if (data == 0X53 && (!temp_flag_2)) {//防止误操作
                temp_flag_2 = 1;
                uart2_index = 0;
            }
        }
    }
}


void USART3_IRQHandler(void) {
    uint8_t data;
    if (USART3->SR & (1 << 5)) {
        data = USART3->DR;
        if (!uart3_receive_flag) {
            if (temp_flag_3) {
                if (data == 0X43) {
                    uart3_receive_flag = 1;
                    mv_pid = 0, animal_inf = 0;
                    if (uart3_[0] == 1)//小球模式
                    {
                        mv_pid += uart3_[2] << 8;
                        mv_pid += uart3_[3];
                        if (uart3_[1] == 2)
                            mv_pid *= (-1);

                    } else if (uart3_[0] == 2)//图片模式
                    {
                        animal_inf = uart3_[1];
                    }

                    temp_flag_3 = 0;
                }
                else { uart3_[uart3_index++] = data; }
                if (uart3_index == MAX_SIZE) {
                    memset(&uart3_, 0, sizeof(uart3_));
                    temp_flag_3 = 0;
                }
            }
            if (data == 0X53 && (!temp_flag_3)) {//防止误操作
                temp_flag_3 = 1;
                uart3_index = 0;
            }
        }

    }
}

void UART4_IRQHandler(void) {
    //协议内容
    uint8_t data;
    if (UART4->SR & (1 << 5)) {
        data = UART4->DR;
        if (!uart4_receive_flag) {//未接收完成
            if (temp_flag_4) {
                if (data == 0X43) {
                    uart4_receive_flag = 1;
                    temp_flag_4 = 0;
                }
                else { uart4_[uart4_index++] = data; }
                if (uart4_index == MAX_SIZE) {
                    temp_flag_4 = 0;
                    memset(&uart4_, 0, sizeof(uart4_));
                }
            }
            if (data == 0X53 && (!temp_flag_4)) {//防止误操作
                temp_flag_4 = 1;
                uart4_index = 0;
            }
        }
    }
}

void UART5_IRQHandler(void) {
    uint8_t data;
    if (UART5->SR & (1 << 5)) {
        data = UART5->DR;
        if (!uart5_receive_flag) {
            if (temp_flag_5) {
                if (data == 0X43) {
                    uart5_receive_flag = 1;
                    temp_flag_5 = 0;
                } else {
                    uart5_[uart5_index++] = data;
                }
                if (uart5_index == MAX_SIZE) {
                    temp_flag_5 = 0;
                    memset(&uart5_, 0, sizeof(uart5_));
                }
            }
            if (data == 0X53 && (!temp_flag_5)) {//防止误操作
                temp_flag_5 = 1;
                uart5_index = 0;
            }
        }
    }
}

void UART_global_handler(void) {
#define move_speed_1  5000
#define move_speed_2 5000
    if (uart2_receive_flag) {
        uart2_receive_flag = 0;
    }
    if (uart3_receive_flag) {
        uart3_receive_flag = 0;
    }
    if (uart4_receive_flag) {
        uart4_receive_flag = 0;
    }
    if (uart5_receive_flag) {
        uart5_receive_flag = 0;
    }
}

int Animal_Recognition(void) {
    uint8_t cmd[3] = {(int) 'P', (int) 'P', (int) 'P'};
    HAL_UART_Transmit(&huart3, cmd, 3, 0xff);
    while (!animal_inf);
    switch (animal_inf) {
        case 1:
            //TODO
            break;
        case 2:
            //TODO
            break;
        case 3:
            //TODO
            break;
        default:
            break;
    }
    animal_inf = 0;
}