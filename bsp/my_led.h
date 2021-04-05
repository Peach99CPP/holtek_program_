//
// Created by peachRJ on 2021/4/15.
//

#ifndef HOLTEK_MY_LED_H
#define HOLTEK_MY_LED_H
#include "main.h"
#include "bmp.h"
#define USE_HORIZONTAL 2  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 128
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 128
#endif

#define OLED_BL_ON() HAL_GPIO_WritePin(BL_GPIO_Port,BL_Pin,GPIO_PIN_SET)
#define OLED_BL_OFF() HAL_GPIO_WritePin(BL_GPIO_Port,BL_Pin,GPIO_PIN_SET)
//
#define OLED_DC_SET() HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,GPIO_PIN_SET)
#define OLED_DC_RESET() HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,GPIO_PIN_RESET)

//
#define OLED_RES_SET() HAL_GPIO_WritePin(RES_GPIO_Port,RES_Pin,GPIO_PIN_SET)
#define OLED_RES_RESET() HAL_GPIO_WritePin(RES_GPIO_Port,RES_Pin,GPIO_PIN_RESET)
//
#define OLED_CS_SET() HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET)
#define OLED_CS_RESET() HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_RESET)
//
#define  OLED_SCLK_1_SET() HAL_GPIO_WritePin(SCL_1_GPIO_Port,SCL_1_Pin,GPIO_PIN_SET)
#define OLED_SCLK_1_RESET() HAL_GPIO_WritePin(SCL_1_GPIO_Port,SCL_1_Pin,GPIO_PIN_RESET)
#define OLED_SCLK_2_SET() HAL_GPIO_WritePin(SCL_2_GPIO_Port,SCL_2_Pin,GPIO_PIN_SET)
#define OLED_SCLK_2_RESET() HAL_GPIO_WritePin(SCL_2_GPIO_Port,SCL_2_Pin,GPIO_PIN_RESET)

#define OLED_SDA_1_SET() HAL_GPIO_WritePin(SDA_1_GPIO_Port,SDA_1_Pin,GPIO_PIN_SET)
#define OLED_SDA_1_RESET() HAL_GPIO_WritePin(SDA_1_GPIO_Port,SDA_1_Pin,GPIO_PIN_RESET)

#define OLED_SDA_2_SET() HAL_GPIO_WritePin(SDA_2_GPIO_Port,SDA_2_Pin,GPIO_PIN_SET)
#define OLED_SDA_2_RESET() HAL_GPIO_WritePin(SDA_2_GPIO_Port,SDA_2_Pin,GPIO_PIN_RESET)
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

#endif //HOLTEK_MY_LED_H
