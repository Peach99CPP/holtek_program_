//
// Created by peachRJ on 2021/4/14.
//

#include "LCD_Driver.h"
#include "timer_it.h"
//
////通过SPI总线传输一字节数据
//void SPI_WriteData(int id, u8 data) {
//    unsigned char i = 0;
//    if (id == 1) {
//        for (i = 8; i > 0; --i
//                ) {
//            if (data & 0X80) LCD_SDA_1_SET;
//            else
//                LCD_SDA_1_CLR;
//        }
//        LCD_SCL_1_CLR;
//        LCD_SCL_1_SET;
//        data <<= 1;
//    }
//    else if (id == 2) {
//        for (i = 8; i > 0; --i
//                ) {
//            if (data & 0X80) LCD_SDA_2_SET;
//            else
//                LCD_SDA_2_CLR;
//        }
//        LCD_SCL_2_CLR;
//        LCD_SCL_2_SET;
//        data <<= 1;
//    }
//
//
//}
//
//void Lcd_WriteIndex(int id, u8 index) {
//    if (id == 1) {
//        //SPI 写命令时序开始
//        LCD_CS_CLR;
//        LCD_RS_CLR;
//        SPI_WriteData(1, index);
//        LCD_CS_SET;
//    }
//    else if (id == 2) {
//        SPI_WriteData(2, index);
//    }
//}
//
//void Lcd_WriteData(int id, u8 Data) {
//    if (id == 1) {
//        LCD_CS_CLR;
//        LCD_RS_SET;
//        SPI_WriteData(1, Data);
//        LCD_CS_SET;
//    }
//    else if (id == 2) {
//
//        LCD_CS_CLR;
//        LCD_RS_SET;
//        SPI_WriteData(2, Data);
//        LCD_CS_SET;
//    }
//}
//void LCD_WriteData_16Bit(int id,u16 Data)
//{
//    if(id==1) {
//        LCD_CS_CLR;
//        LCD_RS_SET;
//        SPI_WriteData(1,Data >> 8);    //写入高8位数据
//        SPI_WriteData(1,Data);            //写入低8位数据
//        LCD_CS_SET;
//    }
//    else if(id==2)
//    {
//        LCD_CS_CLR;
//        LCD_RS_SET;
//        SPI_WriteData(2,Data >> 8);    //写入高8位数据
//        SPI_WriteData(2,Data);            //写入低8位数据
//        LCD_CS_SET;
//    }
//}
//void Lcd_WriteReg(int id,u8 Index,u8 Data)
//{
//    Lcd_WriteIndex(id,Index);
//    Lcd_WriteData(id,Data);
//}
//void Lcd_Reset(void)
//{
//    LCD_RST_CLR;
//    delay_ms(100);
//    LCD_RST_SET;
//    delay_ms(50);
//}

