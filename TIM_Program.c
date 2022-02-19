#include	"Std.h"
#include	"Bit_Math.h"

#include	"DIO_Interface.h"

#include	"TIM_Private.h"
#include	"TIM_Interface.h"



void	TIM_voidEnableTIM1(void)
{
	SET_BIT(TCCR1A_REG,PIN7);
	SET_BIT(TCCR1A_REG,PIN1);
	SET_BIT(TCCR1B_REG,PIN4);
	SET_BIT(TCCR1B_REG,PIN3);
	SET_BIT(TCCR1B_REG,PIN1);
	SET_BIT(TCCR1B_REG,PIN0);
}
void	TIM_voidDisableTIM1(void)
{
	CLR_BIT(TCCR1A_REG,PIN7);
	CLR_BIT(TCCR1A_REG,PIN1);
	CLR_BIT(TCCR1B_REG,PIN4);
	CLR_BIT(TCCR1B_REG,PIN3);
	CLR_BIT(TCCR1B_REG,PIN1);
	CLR_BIT(TCCR1B_REG,PIN0);
}

