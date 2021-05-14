//
// Created by peachRJ on 2021/4/15.
//

#ifndef HOLTEK_MY_LED_H
#define HOLTEK_MY_LED_H
#include "main.h"
#include "bmp.h"
#include "font.h"
#include "holtek_font.h"
#include "chinese_font.h"
#define USE_HORIZONTAL 0  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 128
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 128
#endif
/*
 * 以下宏定义为屏幕A的底层驱动
 */
#define A_OLED_BL_ON() HAL_GPIO_WritePin(A_BL_GPIO_Port,A_BL_Pin,GPIO_PIN_SET)
#define A_OLED_BL_OFF() HAL_GPIO_WritePin(A_BL_GPIO_Port,A_BL_Pin,GPIO_PIN_RESET)
//
#define A_OLED_DC_SET() HAL_GPIO_WritePin(A_DC_GPIO_Port,A_DC_Pin,GPIO_PIN_SET)
#define A_OLED_DC_RESET() HAL_GPIO_WritePin(A_DC_GPIO_Port,A_DC_Pin,GPIO_PIN_RESET)

//
#define A_OLED_RES_SET() HAL_GPIO_WritePin(A_RES_GPIO_Port,A_RES_Pin,GPIO_PIN_SET)
#define A_OLED_RES_RESET() HAL_GPIO_WritePin(A_RES_GPIO_Port,A_RES_Pin,GPIO_PIN_RESET)
//
#define A_OLED_CS_SET() HAL_GPIO_WritePin(A_CS_GPIO_Port,A_CS_Pin,GPIO_PIN_SET)
#define A_OLED_CS_RESET() HAL_GPIO_WritePin(A_CS_GPIO_Port,A_CS_Pin,GPIO_PIN_RESET)

#define A_OLED_SDA_SET() HAL_GPIO_WritePin(A_SDA_GPIO_Port,A_SDA_Pin,GPIO_PIN_SET)
#define A_OLED_SDA_RESET() HAL_GPIO_WritePin(A_SDA_GPIO_Port,A_SDA_Pin,GPIO_PIN_RESET)

#define  A_OLED_SCLK_SET() HAL_GPIO_WritePin(A_SCL_GPIO_Port,A_SCL_Pin,GPIO_PIN_SET)
#define  A_OLED_SCLK_RESET() HAL_GPIO_WritePin(A_SCL_GPIO_Port,A_SCL_Pin,GPIO_PIN_RESET)

//
/*
 * 以下为屏幕B的底层 驱动
 */
#define B_OLED_BL_ON() HAL_GPIO_WritePin(B_BL_GPIO_Port,B_BL_Pin,GPIO_PIN_SET)
#define B_OLED_BL_OFF() HAL_GPIO_WritePin(B_BL_GPIO_Port,B_BL_Pin,GPIO_PIN_RESET)
//
#define B_OLED_DC_SET() HAL_GPIO_WritePin(B_DC_GPIO_Port,B_DC_Pin,GPIO_PIN_SET)
#define B_OLED_DC_RESET() HAL_GPIO_WritePin(B_DC_GPIO_Port,B_DC_Pin,GPIO_PIN_RESET)

//
#define B_OLED_RES_SET() HAL_GPIO_WritePin(B_RES_GPIO_Port,B_RES_Pin,GPIO_PIN_SET)
#define B_OLED_RES_RESET() HAL_GPIO_WritePin(B_RES_GPIO_Port,B_RES_Pin,GPIO_PIN_RESET)
//
#define B_OLED_CS_SET() HAL_GPIO_WritePin(B_CS_GPIO_Port,B_CS_Pin,GPIO_PIN_SET)
#define B_OLED_CS_RESET() HAL_GPIO_WritePin(B_CS_GPIO_Port,B_CS_Pin,GPIO_PIN_RESET)

#define B_OLED_SCLK_SET() HAL_GPIO_WritePin(B_SCL_GPIO_Port,B_SCL_Pin,GPIO_PIN_SET)
#define B_OLED_SCLK_RESET() HAL_GPIO_WritePin(B_SCL_GPIO_Port,B_SCL_Pin,GPIO_PIN_RESET)


#define B_OLED_SDA_SET() HAL_GPIO_WritePin(B_SDA_GPIO_Port,B_SDA_Pin,GPIO_PIN_SET)
#define B_OLED_SDA_RESET() HAL_GPIO_WritePin(B_SDA_GPIO_Port,B_SDA_Pin,GPIO_PIN_RESET)
/*/
 * 通用命令
 */
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
//
//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE           	 0x001F
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //棕色
#define BRRED 			     0XFC07 //棕红色
#define GRAY  			     0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色

#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			     0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
//
#define	u8 unsigned char
#define	u16 unsigned int
#define	u32 unsigned long

extern  u16 BACK_COLOR;   //背景色
void LCD_showTest(int id,u16 x,u16 y,u8 index,u16 color);
void LCD_BigNum(int id,u16 x,u16 y,u8 num,u16 color);
void LCD_Writ_Bus(int id,u8 dat);
void LCD_WR_DATA8(int id,u8 dat);
void LCD_WR_DATA(int id,u16 dat);
void LCD_WR_REG(int id,u8 dat);
void LCD_Address_Set(int id,u16 x1,u16 y1,u16 x2,u16 y2);
void Lcd_Init(int id);
void LCD_Clear(int id,u16 Color);
void LCD_ShowChinese(int id,u16 x,u16 y,u8 index,u8 size,u16 color);
void LCD_DrawPoint(int id,u16 x,u16 y,u16 color);
void LCD_DrawPoint_big(int id,u16 x,u16 y,u16 color);
void LCD_Fill(int id,u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
void LCD_DrawLine(int id,u16 x1,u16 y1,u16 x2,u16 y2,u16 color);
void LCD_DrawRectangle(int id,u16 x1, u16 y1, u16 x2, u16 y2,u16 color);
void Draw_Circle(int id,u16 x0,u16 y0,u8 r,u16 color);
void LCD_ShowChar(int id,u16 x,u16 y,u8 num,u8 mode,u16 color);
void LCD_ShowString(int id,u16 x,u16 y,const u8 *p,u16 color);
u32 mypow(int id,u8 m,u8 n);
void LCD_ShowNum(int id,u16 x,u16 y,u16 num,u8 len,u16 color);
void LCD_ShowNum1(int id,u16 x,u16 y,float num,u8 len,u16 color);
void LCD_ShowPicture(int id,u16 x1,u16 y1,u16 x2,u16 y2);
void LCD_ShowMyChinese(int id,u8 index,u16 x,u16 y,const u8 * ptr,u16 x_size,u16 y_size,u16 color );
void LCD_ShowMyPicture(int id,u16 x,u16 y,const u8 * ptr,u16 x_size,u16 y_size);
void LCD_Show_Expressions(int id);
void Show_Chinese(int number);
void LED_ShowMY_Num(int id,int num);
#endif //HOLTEK_MY_LED_H
