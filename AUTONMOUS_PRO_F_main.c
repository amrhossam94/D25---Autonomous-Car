#define		F_CPU		16000000UL
#include	"Std.h"
#include	"Bit_Math.h"
#include	<util/delay.h>


#include	"DIO_Interface.h"
#include	"LCD_Interface.h"
#include	"GIE_Interface.h"
#include	"TIM_Interface.h"
#include	"EXT_Interface.h"
#include	"ULTRA_Interface.h"
#include	"DM_Interface.h"
#include	"TIM_Private.h"



volatile  u16 StartFlag = 1;
volatile  u16 Pulse;
volatile  u16 Distance = 0;
volatile  u16 CritcalDis = 45;
volatile  u8  INTFLAG =0;


void	EXT0_Function(void);

int main()
{   
    EXT0_voidCallBack(EXT0_Function);
	
	DIO_voidSetPortDirection(PORTA,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	DIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN7,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN6,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);
	
	
	
	LCD_voidInt4Bit();
	GIE_voidEnable();
	EXT0_voidInt();
	EXT0_voidEnable();
	
	TCNT1_REG = 0;
	
	    DIO_voidSetPinValue(PORTD,PIN7,HIGH);
	    _delay_us(50);
	    DIO_voidSetPinValue(PORTD,PIN7,LOW);
	    _delay_us(950);
	 
	 
	while(1)
	{
	
		
		ULTRA_voidSetTrig();
		Distance = (Pulse / 932.9);
		LCD_voidSetCMD4Bit(0x80);
		LCD_voidWriteString("AUTONOMOUS CAR");
		LCD_voidSetCMD4Bit(0xC0);
		LCD_voidWriteString("Distance = ");
		LCD_voidSetCMD4Bit(0xCA);
		LCD_voidWriteInteger(Distance);
		LCD_voidSetCMD4Bit(0xCE);
		LCD_voidWriteString("CM");
		
		
		
		
		while(Distance < CritcalDis && StartFlag == 1 )
		{ 
			
		     Servo_voidServoLED();
			 DM_voidStopCar();
			 _delay_us(150);
			 
			 DIO_voidSetPinValue(PORTD,PIN7,HIGH);
			 _delay_us(90);
			 DIO_voidSetPinValue(PORTD,PIN7,LOW);
			 _delay_us(910);
			 
			  DM_voidCarForward();
			 
			 ULTRA_voidSetTrig();
			Distance = (Pulse / 932.9);
			
			
			
	    }
         StartFlag = 1;
		 _delay_us(150);
		 
		 while(Distance < CritcalDis)
		 {
			 ULTRA_voidSetTrig();
			 Distance = (Pulse / 932.9);
		 }
		 
		 
		 DIO_voidSetPinValue(PORTD,PIN7,HIGH);
		 _delay_us(50);
		 DIO_voidSetPinValue(PORTD,PIN7,LOW);
		 _delay_us(950);
		
		
       DM_voidCarForward();
       
      
	
	} 
	
	return 0;
}


void	EXT0_Function(void)
{
	if(INTFLAG == 0)
	{
		
		TCCR1B_REG = 0x00;
		INTFLAG=1;
		
	}else
	{
		TCCR1B_REG=0x01;
		Pulse = TCNT1_REG ;
		TCNT1_REG = 0;
		INTFLAG=0;
	}
	
}