#include		"Std.h"
#include		"Bit_Math.h"
#include		"util/delay.h"



#include		"GIE_Private.h"		
#include		"GIE_Interface.h"


  
void	GIE_voidEnable(void)
{
	SET_BIT(SREG_REG,GIE_BIT);
}
void	GIE_voidDisable(void)
{
	CLR_BIT(SREG_REG,GIE_BIT);
}


