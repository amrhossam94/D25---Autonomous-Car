#include		"Std.h"
#include		"Bit_Math.h"
#include		<util/delay.h>

#include		"DIO_Interface.h"
		

#include		"DM_Interface.h"



void		DM_voidCarForward(void)
{
	       DIO_voidSetPinValue(PORTC,PIN0,HIGH);
		   DIO_voidSetPinValue(PORTC,PIN1,LOW);
		   DIO_voidSetPinValue(PORTC,PIN6,HIGH);
		   DIO_voidSetPinValue(PORTC,PIN7,LOW);
}
void		DM_voidCarBackword(void)
{
	       DIO_voidSetPinValue(PORTC,PIN0,LOW);
		   DIO_voidSetPinValue(PORTC,PIN1,HIGH);
		   DIO_voidSetPinValue(PORTC,PIN6,LOW);
		   DIO_voidSetPinValue(PORTC,PIN7,HIGH);
}
void		DM_voidStopCar(void)
{
	       DIO_voidSetPinValue(PORTC,PIN0,LOW);
		   DIO_voidSetPinValue(PORTC,PIN1,LOW);
		   DIO_voidSetPinValue(PORTC,PIN6,LOW);
		   DIO_voidSetPinValue(PORTC,PIN7,LOW);
}