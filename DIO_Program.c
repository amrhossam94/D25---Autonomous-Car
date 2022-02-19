#include	"Std.h"
#include	"Bit_Math.h"

#include	"DIO_Private.h"
#include	"DIO_Interface.h"





void	DIO_voidSetPinDirection(u8	PortID,u8	PinID, u8	Direction)
{
	if(PortID < 4 && PinID < 8)
	{
		if(Direction == 1)
		{
			switch(PortID)
			{
				case PORTA :		SET_BIT(DDRA_REG,PinID);		break;	
				case PORTB :		SET_BIT(DDRB_REG,PinID);		break;
				case PORTC :		SET_BIT(DDRC_REG,PinID);		break;
				case PORTD :		SET_BIT(DDRD_REG,PinID);		break;				
			}                               
		}else if(Direction == 0)
		{
			switch(PortID)
			{
				case PORTA :		CLR_BIT(DDRA_REG,PinID);		break;	
				case PORTB :		CLR_BIT(DDRB_REG,PinID);		break;
				case PORTC :		CLR_BIT(DDRC_REG,PinID);		break;
				case PORTD :		CLR_BIT(DDRD_REG,PinID);		break;				
			}             
		}
	}else{
		
	}
	
}
void	DIO_voidSetPinValue(u8	PortID,u8 PinID,u8 Value)
{
	if(PortID < 4 && PinID <8)
	{
		if(Value == 1)
		{
			switch(PortID)
			{
				case PORTA:		SET_BIT(PORTA_REG,PinID);	break;
				case PORTB:		SET_BIT(PORTB_REG,PinID);	break;
				case PORTC:		SET_BIT(PORTC_REG,PinID);	break;
				case PORTD:		SET_BIT(PORTD_REG,PinID);	break;
			}
		}else if(Value == 0)
		 {
			switch(PortID)
			{												
				case PORTA:		CLR_BIT(PORTA_REG,PinID);	break;
				case PORTB:		CLR_BIT(PORTB_REG,PinID);	break;
				case PORTC:		CLR_BIT(PORTC_REG,PinID);	break;
				case PORTD:		CLR_BIT(PORTD_REG,PinID);	break;
		 	}
		 }
	}else{
		
	}
	
}
u8		DIO_u8getpinValue(u8 PortID,u8 PinID)
{
	u8 Local_u8Value = 0xFF;
	if(PortID < 4 && PinID <8)
	{
		switch(PortID)
		{
			case PORTA:		 Local_u8Value = GET_BIT(PINA_REG,PinID);			break;
			case PORTB:		 Local_u8Value = GET_BIT(PINB_REG,PinID);			break;
			case PORTC:		 Local_u8Value = GET_BIT(PINC_REG,PinID);			break;
			case PORTD:		 Local_u8Value = GET_BIT(PIND_REG,PinID);			break;
		}
	}
	return Local_u8Value ;
}


void	DIO_voidSetPortDirection(u8	PortID, u8	Direction)
{
	if(PortID < 4)
	{
		if(Direction == 1)
		{	
		  switch(PortID)
		  {
			    case PORTA:			SET_PORT(DDRA_REG, 0xFF);				break;
				case PORTB:			SET_PORT(DDRB_REG, 0xFF);				break;
				case PORTC:			SET_PORT(DDRC_REG, 0xFF);				break;
				case PORTD:			SET_PORT(DDRD_REG, 0xFF);				break;
			
		  }
		}
		if(Direction == 0)
		{	
		  switch(PortID)
		  {
			    case PORTA:		SET_PORT(DDRA_REG , 0X00);			break;
				case PORTB:		SET_PORT(DDRB_REG , 0X00);			break;
				case PORTC:		SET_PORT(DDRC_REG , 0X00);			break;
				case PORTD:		SET_PORT(DDRD_REG , 0X00);			break;
			
		  }
		}
	}else{
		
		
	     }
}

void	DIO_voidSetPortValue(u8	PortID , u8 Value)
{
	if(PortID < 4)
	{
		switch(PortID)
		  {
			    case PORTA:		SET_PORT(PORTA_REG , Value);	break;
				case PORTB:		SET_PORT(PORTB_REG , Value);	break;
				case PORTC:		SET_PORT(PORTC_REG , Value);	break;
				case PORTD:		SET_PORT(PORTD_REG , Value);	break;
			
		  }
	}else{
		
		
	     }
}

u8		DIO_u8GetPortValue(u8 PortID)
{
	u8 Local_u8Value =0xFF;
	if(PortID < 4)
	{
		switch(PortID)
		{
			    case PORTA:			Local_u8Value  = PORTA_REG;		break;
			    case PORTB:			Local_u8Value  = PORTB_REG;		break;
			    case PORTC:			Local_u8Value  = PORTC_REG;		break;
			    case PORTD:			Local_u8Value  = PORTD_REG;		break;
			
		}
	}
	return Local_u8Value;
}