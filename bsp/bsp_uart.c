//
// Created by peachRJ on 2021/4/3.
//

#include <usart.h>
#include "bsp_uart.h"
#include "retarget.h"

int uart2_receive_flag, uart3_receive_flag, uart4_receive_flag, uart5_receive_flag,
        uart2_index, uart3_index, uart4_index, uart4_index, uart5_index;
static int temp_flag_4 = 0, temp_flag_2 = 0, temp_flag_3 = 0, temp_flag_5 = 0;
#define MAX_SIZE 199
uint8_t uart2_[MAX_SIZE], urat3_[MAX_SIZE], uart4_[MAX_SIZE], uart5_[MAX_SIZE];

void Uarts_IT_Init(void) {
    __HAL_UART_ENABLE(&huart2);
    __HAL_UART_ENABLE(&huart3);
    __HAL_UART_ENABLE(&huart4);
    __HAL_UART_ENABLE(&huart5);
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
    __HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE);
    __HAL_UART_ENABLE_IT(&huart4, UART_IT_RXNE);
    __HAL_UART_ENABLE_IT(&huart5, UART_IT_RXNE);
}

void UART_transmit(UART_HandleTypeDef *huart, char ch[])//通过全局printf函数发送数据
{
    RetargetInit(huart);
    printf("%s", ch);
}

void UART4_IRQHandler() {
    //协议内容
    uint8_t data;
    if (UART4->SR & (1 << 5)) {
        data = UART4->DR;
        if (temp_flag_4)//S接收完成
        {
            if (data == 0X43) {
                uart4_receive_flag = 1;
                temp_flag_4 = 0;
            }
            else { uart4_[uart4_index++] = data; }
            if (uart4_index == MAX_SIZE) {
                temp_flag_4 = 0;
                uart4_receive_flag = 0;
            }
        }
        if (data == 0X53) {
            temp_flag_4 = 1;
            uart4_index = 0;
        }
    }
}

void UART3_IRQHandler() {
    uint8_t data;
    if (USART3->SR & (1 << 5)) {
        data = USART3->DR;
        if (temp_flag_3) {
            if (data == 0X43) {
                uart3_receive_flag = 1;
                temp_flag_3 = 0;
            }
        }
        if (data == 0X53) {
            temp_flag_3 = 1;
            uart3_index = 0;
        }

    }

}

void UART2_IRQHandler() {

}

void UART5_IRQHandler() {

}
