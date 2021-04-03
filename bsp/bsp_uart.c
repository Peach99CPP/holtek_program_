//
// Created by peachRJ on 2021/4/3.
//

#include <usart.h>
#include "bsp_uart.h"
#include "retarget.h"
#include <string.h>

int uart2_receive_flag, uart3_receive_flag, uart4_receive_flag, uart5_receive_flag,
        uart2_index, uart3_index, uart4_index, uart4_index, uart5_index;
static int temp_flag_4 = 0, temp_flag_2 = 0, temp_flag_3 = 0, temp_flag_5 = 0;
uint8_t uart2_[MAX_SIZE], uart3_[MAX_SIZE], uart4_[MAX_SIZE], uart5_[MAX_SIZE];

void Init_UARTS(void) {//初始化串口
    __HAL_UART_ENABLE(&huart2);
    __HAL_UART_ENABLE(&huart3);
    __HAL_UART_ENABLE(&huart4);
    __HAL_UART_ENABLE(&huart5);
    //全部是接收中断
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

void UART2_IRQHandler() {
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


void UART3_IRQHandler() {
    uint8_t data;
    if (USART3->SR & (1 << 5)) {
        data = USART3->DR;
        if (!uart3_receive_flag) {
            if (temp_flag_3) {
                if (data == 0X43) {
                    uart3_receive_flag = 1;
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

void UART4_IRQHandler() {
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

void UART5_IRQHandler() {
    uint8_t data;
    if (UART5->SR & (1 << 5)) {
        data = UART5->DR;
        if (!uart5_receive_flag) {
            if (temp_flag_5) {
                if (data == 0X43) {
                    uart5_receive_flag = 1;
                    temp_flag_5 = 0;
                }
                else { uart5_[uart5_index++] = data; }
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