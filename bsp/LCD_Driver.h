//
// Created by peachRJ on 2021/4/14.
//

#ifndef HOLTEK_LCD_DRIVER_H
#define HOLTEK_LCD_DRIVER_H
//#include "main.h"
//typedef uint8_t  u8;
//typedef uint16_t u16;
//#define X_MAX_PIXEL	        128
//#define Y_MAX_PIXEL	        160
//
//#define RED  	0xf800
//#define GREEN	0x07e0
//#define BLUE 	0x001f
//#define WHITE	0xffff
//#define BLACK	0x0000
//#define YELLOW  0xFFE0
//#define GRAY0   0xEF7D   	//灰色0 3165 00110 001011 00101
//#define GRAY1   0x8410      	//灰色1      00000 000000 00000
//#define GRAY2   0x4208      	//灰色2  1111111111011111
//
//#define LCD_CTRLA   	  	GPIOC		//定义TFT数据端口
//#define LCD_CTRLB   	  	GPIOB		//定义TFT数据端口
//#define LCD_SCL_1 GPIO_PIN_8
//#define LCD_SCL_2 GPIO_PIN_9
//#define LCD_SDA_1 GPIO_PIN_6
//#define LCD_SDA_2  GPIO_PIN_7
//#define LCD_LED  GPIO_PIN_4
//#define LCD_CS GPIO_PIN_5
//#define LCD_RS GPIO_PIN_6
//#define LCD_RST GPIO_PIN_7
////进行置一
//#define LCD_SCL_1_SET LCD_CTRLA->BSRR=LCD_SCL_1
//#define LCD_SCL_2_SET LCD_CTRLA->BSRR=LCD_SCL_2
//#define LCD_SDA_1_SET LCD_CTRLA->BSRR=LCD_SDA_1
//#define LCD_SDA_2_SET LCD_CTRLA->BSRR=LCD_SDA_2
//
//#define LCD_CS_SET    LCD_CTRLB->BSRR=LCD_CS
//#define LCD_LED_SET    LCD_CTRLB->BSRR=LCD_LED
//#define LCD_RS_SET    LCD_CTRLB->BSRR=LCD_RS
//#define LCD_RST_SET    LCD_CTRLB->BSRR=LCD_RST
////复位
//#define	LCD_SCL_1_CLR  	LCD_CTRLA->BRR=LCD_SCL_1
//#define	LCD_SDA_1_CLR  	LCD_CTRLA->BRR=LCD_SDA_1
//#define	LCD_SCL_2_CLR  	LCD_CTRLA->BRR=LCD_SCL_2
//#define	LCD_SDA_2_CLR  	LCD_CTRLA->BRR=LCD_SDA_2
//#define	LCD_CS_CLR  	LCD_CTRLB->BRR=LCD_CS
//
//#define	LCD_LED_CLR  	LCD_CTRLB->BRR=LCD_LED
//#define	LCD_RST_CLR  	LCD_CTRLB->BRR=LCD_RST
//#define	LCD_RS_CLR  	LCD_CTRLB->BRR=LCD_RS
//
//#define LCD_DATAOUT(x) LCD_DATA->ODR=x; //数据输出
//#define LCD_DATAIN     LCD_DATA->IDR;   //数据输入
//#define LCD_WR_DATA(data){\
//LCD_RS_SET;\
//LCD_CS_CLR;\
//LCD_DATAOUT(data);\
//LCD_WR_CLR;\
//LCD_WR_SET;\
//LCD_CS_SET;\
//}
#endif //HOLTEK_LCD_DRIVER_H
//void LCD_GPIO_Init(void);
//void Lcd_WriteIndex(u8 Index);
//void Lcd_WriteData(u8 Data);
//void Lcd_WriteReg(u8 Index,u8 Data);
//u16 Lcd_ReadReg(u8 LCD_Reg);
//void Lcd_Reset(void);
//void Lcd_Init(void);
//void Lcd_Clear(u16 Color);
//void Lcd_SetXY(u16 x,u16 y);
//void Gui_DrawPoint(u16 x,u16 y,u16 Data);
//unsigned int Lcd_ReadPoint(u16 x,u16 y);
//void Lcd_SetRegion(u16 x_start,u16 y_start,u16 x_end,u16 y_end);
//void LCD_WriteData_16Bit(u16 Data);
