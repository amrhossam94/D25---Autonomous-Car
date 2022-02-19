#include		"Std.h"
#include		"Bit_Math.h"
#include		<util/delay.h>

#include		"DIO_Interface.h"
		
#include		"LCD_Private.h"
#include		"LCD_Interface.h"



void		LCD_voidSetCMD8Bit(u8 CMD)
{
	/*   Set RS to 0 for Enable comandset                  */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_RS , LOW);
	
	/*   Set RS to 0 for Enable comandwrite                */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_RW , LOW);
	
	/*   Set RS to 0 for Enable comandEnable               */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_EN , HIGH);
	
	/*   WRITE CMD                                         */
	DIO_voidSetPortValue(LCD_Data_Port,CMD);
	
	/*   Set RS to 0 for Enable comandDIS                  */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_EN , LOW);
}
void		LCD_voidWriteData8Bit(u8 DATA)
{
	/*   Set RS to 0 for Enable DATAMODE                  */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_RS , HIGH);
	
	/*   Set RS to 0 for Enable DATAwrite                */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_RW , LOW);
	
	/*   Set RS to 0 for Enable DATAEnable               */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_EN , HIGH);
	
	/*   WRITE DATA                                         */
	DIO_voidSetPortValue(LCD_Data_Port,DATA);
	
	/*   Set RS to 0 for Enable DATADIS                  */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_EN , LOW);
}

void		LCD_voidInt8Bit(void)
{
	   _delay_ms(100);
	   LCD_voidSetCMD8Bit(0x38);
	   _delay_ms(50);
	   LCD_voidSetCMD8Bit(0x0E);
	   _delay_ms(50);
	   LCD_voidSetCMD8Bit(0x01);
	   _delay_ms(50);
	   LCD_voidSetCMD8Bit(0x06);
	   _delay_ms(50);
}

void		LCD_voidSetCMD4Bit(u8 CMD)
{
	u8 temp = 0xFF;
	/*   Set RS to 0 for Enable comandset                  */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_RS,LOW);
	
	/*   Set RS to 0 for Enable comandwrite                */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_RW,LOW);
	
	/*   Set RS to 0 for Enable comandEnable               */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_EN,HIGH);
	
	/*   WRITE CMD                                         */
	temp = (CMD & 0XF0)|((DIO_u8GetPortValue(LCD_Data_Port)&0x0F));
	
	DIO_voidSetPortValue(LCD_Data_Port,temp);
	/*   Set RS to 0 for Enable comandDIS                  */
	DIO_voidSetPinValue(LCD_Control_Port, LCD_EN,LOW);
	DIO_voidSetPinValue(LCD_Control_Port, LCD_EN,HIGH);
	
	/*   WRITE CMD                                         */
	temp = (CMD <<4)|((DIO_u8GetPortValue(LCD_Data_Port)&0x0F));
	DIO_voidSetPortValue(LCD_Data_Port,temp);
	/*   Set RS to 0 for Enable comandDIS                  */
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,LOW);
}
void		LCD_voidWriteData4Bit(u8 DATA)
{
	u8 temp = 0x0;
	/*   Set RS to 0 for Enable DATAset                  */
	DIO_voidSetPinValue(LCD_Control_Port,LCD_RS,HIGH);
	
	/*   Set RS to 0 for Enable DATAwrite                */
	DIO_voidSetPinValue(LCD_Control_Port,LCD_RW,LOW);
	
	/*   Set RS to 0 for Enable DATAEnable               */
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,HIGH);
	
	/*   WRITE DATA                                         */
	temp = ((DATA & 0XF0)|(DIO_u8GetPortValue(LCD_Data_Port)&0x0F));
	DIO_voidSetPortValue(LCD_Data_Port,temp);
	/*   Set RS to 0 for Enable DATADIS                  */
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,LOW);
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,HIGH);
	/*   WRITE DATA                                         */
	temp = ((DATA << 4)|(DIO_u8GetPortValue(LCD_Data_Port)&0x0F));
	DIO_voidSetPortValue(LCD_Data_Port,temp);
	/*   Set RS to 0 for Enable DATADIS                  */
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,LOW);
}
void		LCD_voidInt4Bit(void)
{
	_delay_ms(100);
	   LCD_voidSetCMD4Bit(0x33);
	   LCD_voidSetCMD4Bit(0x32);
	   LCD_voidSetCMD4Bit(0x28);
	   _delay_ms(50);
	   LCD_voidSetCMD4Bit(0x0C);
	   _delay_ms(50);
	   LCD_voidSetCMD4Bit(0x01);
	   _delay_ms(50);
	   LCD_voidSetCMD4Bit(0x06);
	   _delay_ms(50);
	   LCD_voidSetCMD4Bit(0x02);
	   _delay_ms(50);
}
	



void 		LCD_voidWriteString(u8 * String)
{
	u8 col = 0;
	while(String[col]!= '\0')
	{
		switch(LCD_MODE)
		{
			case 4 :   LCD_voidWriteData4Bit(String[col]);        break;
			case 8 :   LCD_voidWriteData8Bit(String[col]);        break;
		}
		col++;
	}
}

void 		LCD_voidSetPosXY(u8 Row, u8 col )
{
	if(Row == 1)
	{
		switch(LCD_MODE)
		{
			case 4 :   LCD_voidSetCMD4Bit(0x80+col);        break;
			case 8 :   LCD_voidSetCMD8Bit(0x80+col);        break;
		}
	}else if(Row == 2)
	{
		switch(LCD_MODE)
		{
			case 4 :   LCD_voidSetCMD4Bit(0xC0+col);        break;
			case 8 :   LCD_voidSetCMD8Bit(0xC0+col);        break;
		}
	}
}
  

void 		LCD_voidWriteInteger(u32 Num)
{

	if (LCD_MODE==4)
	{
		LCD_voidWriteData4Bit(((Num/100)%10)+0x30);
		LCD_voidWriteData4Bit(((Num/10)%10)+0x30);
		LCD_voidWriteData4Bit((Num%10)+0x30);
	}else if (LCD_MODE==8){
		LCD_voidWriteData8Bit(((Num/100)%10)+0x30);
		LCD_voidWriteData8Bit(((Num/10)%10)+0x30);
		LCD_voidWriteData8Bit((Num%10)+0x30);
	}
}
