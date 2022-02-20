
#include "NXP/iolpc2148.h"

#define LCD_RS IO1PIN_bit.P1_24
#define LCD_E  IO1PIN_bit.P1_25

#define  ON    1
#define  OFF   0

void lcd_command(char cmd);
void lcd_data(char data);
void lcd_gotoXY(char row, char col);
void LCD_WriteChar(char character);
void LCD_WriteString(char *buffer);
void lcd_init(void);
void lcd_backlight(char option);
void LCD_Newline(void);
void LCD_Clear(void);
