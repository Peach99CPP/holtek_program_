/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define motor2_p_Pin GPIO_PIN_2
#define motor2_p_GPIO_Port GPIOC
#define motor1_p_Pin GPIO_PIN_0
#define motor1_p_GPIO_Port GPIOB
#define motor1_n_Pin GPIO_PIN_1
#define motor1_n_GPIO_Port GPIOB
#define UNUSED_Pin GPIO_PIN_2
#define UNUSED_GPIO_Port GPIOB
#define tracker_1_Pin GPIO_PIN_12
#define tracker_1_GPIO_Port GPIOB
#define tracker_2_Pin GPIO_PIN_13
#define tracker_2_GPIO_Port GPIOB
#define tracker_3_Pin GPIO_PIN_14
#define tracker_3_GPIO_Port GPIOB
#define tracker_4_Pin GPIO_PIN_15
#define tracker_4_GPIO_Port GPIOB
#define SDA_1_Pin GPIO_PIN_6
#define SDA_1_GPIO_Port GPIOC
#define SDA_2_Pin GPIO_PIN_7
#define SDA_2_GPIO_Port GPIOC
#define SCL_1_Pin GPIO_PIN_8
#define SCL_1_GPIO_Port GPIOC
#define SCL_2_Pin GPIO_PIN_9
#define SCL_2_GPIO_Port GPIOC
#define avd_Pin GPIO_PIN_10
#define avd_GPIO_Port GPIOA
#define green_Pin GPIO_PIN_11
#define green_GPIO_Port GPIOA
#define blue_Pin GPIO_PIN_12
#define blue_GPIO_Port GPIOA
#define red_Pin GPIO_PIN_15
#define red_GPIO_Port GPIOA
#define motor2_n_Pin GPIO_PIN_3
#define motor2_n_GPIO_Port GPIOB
#define BL_Pin GPIO_PIN_4
#define BL_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_5
#define CS_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_6
#define DC_GPIO_Port GPIOB
#define RES_Pin GPIO_PIN_7
#define RES_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
