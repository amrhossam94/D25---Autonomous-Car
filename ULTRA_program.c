#include		"Std.h"
#include		"Bit_Math.h"
#include		"util/delay.h"

#include		"DIO_Interface.h"
#include		"ULTRA_Interface.h"
		



void		ULTRA_voidSetTrig(void)
{
	     DIO_voidSetPinValue(PORTD,PIN0,HIGH);
		 _delay_us(10);
		 DIO_voidSetPinValue(PORTD,PIN0,LOW);
		 
}
