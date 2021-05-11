//
// Created by peachRJ on 2021/4/3.
//

#ifndef HOLTEK_BSP_UART_H
#define HOLTEK_BSP_UART_H
#include "main.h"
#define MAX_SIZE 199
void Init_UARTS(void);
void UART_transmit(UART_HandleTypeDef* huart,char ch[] );
extern int uart2_receive_flag, uart3_receive_flag, uart4_receive_flag, uart5_receive_flag,
        uart2_index,uart3_index,uart4_index,uart5_index,animal_inf,mv_pid;
void Animal_Recognition(void);
extern uint8_t uart2_[MAX_SIZE], uart3_[MAX_SIZE], uart4_[MAX_SIZE], uart5_[MAX_SIZE];
extern void UART_global_handler(void);
#endif //HOLTEK_BSP_UART_H
