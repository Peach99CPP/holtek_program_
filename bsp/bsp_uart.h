//
// Created by peachRJ on 2021/4/3.
//

#ifndef HOLTEK_BSP_UART_H
#define HOLTEK_BSP_UART_H
#include "main.h"
void set_uarts_it(void);
void UART_transmit(UART_HandleTypeDef* huart,char ch[] );
int uart2_receive_flag, uart3_receive_flag, uart4_receive_flag, uart5_receive_flag,
        uart2_index,uart3_index,uart4_index,uuart5_index;
#endif //HOLTEK_BSP_UART_H
