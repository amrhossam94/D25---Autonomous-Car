#include		"Std.h"
#include		"Bit_Math.h"
#include	<util/delay.h>
#include		"DIO_interface.h"

#include		"Servo_interface.h"



void	Servo_voidServoTurn(u8 angle)
{
	
	switch(angle)
	  {   case 0 :   
		             DIO_voidSetPinValue(PORTD,PIN7,HIGH);
			         _delay_us(50);
			         DIO_voidSetPinValue(PORTD,PIN7,LOW);
			         _delay_us(950); 
					 
	     break;
		case 90 :  
					 DIO_voidSetPinValue(PORTD,PIN7,HIGH);
					 _delay_us(90);
					 DIO_voidSetPinValue(PORTD,PIN7,LOW);
					 _delay_us(910);    
		 break;
		 case 180 :
		            DIO_voidSetPinValue(PORTD,PIN7,HIGH);
		            _delay_us(100);
		            DIO_voidSetPinValue(PORTD,PIN7,LOW);
		            _delay_us(900);
		 break;
	  }
			 
}
void	Servo_voidServoLED(void)
{
           DIO_voidSetPinValue(PORTD,PIN5,HIGH);
           _delay_ms(20);
           DIO_voidSetPinValue(PORTD,PIN5,LOW);
           _delay_ms(20);
}