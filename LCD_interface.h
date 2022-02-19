#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H


#define		LCD_MODE         		4
#define		LCD_Control_Port		PORTA
#define		LCD_Data_Port			PORTA
#define		LCD_RS				    PIN1
#define		LCD_RW			        PIN2
#define		LCD_EN			        PIN3


void		LCD_voidSetCMD8Bit(u8 CMD);
void		LCD_voidWriteData8Bit(u8 DATA);
void		LCD_voidInt8Bit(void);

void		LCD_voidSetCMD4Bit(u8 CMD);
void		LCD_voidWriteData4Bit(u8 DATA);
void		LCD_voidInt4Bit(void);


void 		LCD_voidWriteString(u8 * String);
void 		LCD_voidSetPosXY(u8 Row, u8 col );


void 		LCD_voidWriteInteger(u32 Num);


#endif