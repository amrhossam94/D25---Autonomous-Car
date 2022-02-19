#include		"Std.h"
#include		"Bit_Math.h"
#include		"util/delay.h"

#include		"DIO_Interface.h"
#include		"GIE_Interface.h"

#include		"EXT_Private.h"
#include		"EXT_Interface.h"

#include		"TIM_Private.h"


#ifndef		NULL
#define		NULL		(void *)0
#endif

static void (*Call_Back_0)(void) = NULL;
static void (*Call_Back_1)(void) = NULL;
static void (*Call_Back_2)(void) = NULL;

/*          FUNCTIONS OF EXT0               */

void	EXT0_voidInt(void)
{
	/*        CHOSING THE SENSING MODE OF EXT0               */
	#if		    EXTI0_SenseMode	== LOW_LEVEL
	        CLR_BIT(MCUCR_REG,0);
	        CLR_BIT(MCUCR_REG,1);
	#elif		EXTI0_SenseMode	== ANY_EDGE
	        SET_BIT(MCUCR_REG,0);
	        CLR_BIT(MCUCR_REG,1);
	#elif		EXTI0_SenseMode	== FALLING_EDGE
	        CLR_BIT(MCUCR_REG,0);
	        SET_BIT(MCUCR_REG,1);
	#elif		EXTI0_SenseMode	== RISING_EDGE
	        SET_BIT(MCUCR_REG,0);
	        SET_BIT(MCUCR_REG,1);
	#else    
		    #error	"Invalid Sensing Mode Choice "
		
	#endif
	
	/*        DISABLE INTERUPTS              */
	       CLR_BIT(GICR_REG,6);
		   CLR_BIT(GICR_REG,5);
		   CLR_BIT(GICR_REG,7);
		   
	/*        CLEAR INTERUPT FLAG OF EXT0             */
	       CLR_BIT(GIFR_REG,6);
	
}
void	EXT0_voidEnable(void)
{
	   GIE_voidEnable();
	   SET_BIT(GICR_REG,6);
}
void	EXT0_voidDisable(void)
{
	   CLR_BIT(GICR_REG,6);
}



/*        FUNCTIONS OF EXT1               */


void	EXT1_voidInt(void)
{
	
	/*        CHOSING THE SENSING MODE OF EXT1               */
	#if		    EXTI1_SenseMode	== LOW_LEVEL
	        CLR_BIT(MCUCR_REG,2);
	        CLR_BIT(MCUCR_REG,3);
	#elif		EXTI1_SenseMode	== ANY_EDGE
	        SET_BIT(MCUCR_REG,2);
	        CLR_BIT(MCUCR_REG,3);
	#elif		EXTI1_SenseMode	== FALLING_EDGE
	        CLR_BIT(MCUCR_REG,2);
	        SET_BIT(MCUCR_REG,3);
	#elif		EXTI1_SenseMode	== RISING_EDGE
	        SET_BIT(MCUCR_REG,2);
	        SET_BIT(MCUCR_REG,3);
	#else    
		    #error	"Invalid Sensing Mode Choice "
		
	#endif
	/*        DISABLE INTERUPTS              */
	       CLR_BIT(GICR_REG,6);
		   CLR_BIT(GICR_REG,5);
		   CLR_BIT(GICR_REG,7);
		   
	/*        CLEAR INTERUPT FLAG OF EXT1             */
	       CLR_BIT(GIFR_REG,7);
}
void	EXT1_voidEnable(void)
{
	   GIE_voidEnable();
	   SET_BIT(GICR_REG,7);
	
}
void	EXT1_voidDisable(void)
{
	    CLR_BIT(GICR_REG,7);
}






/*        FUNCTIONS OF EXT2               */

void	EXT2_voidInt(void)
{
	/*        CHOSING THE SENSING MODE OF EXT2               */
	#if		    EXTI2_SenseMode	== FALLING_EDGE
	            CLR_BIT(MCUCSR_REG,6);
	#elif		EXTI2_SenseMode	== RISING_EDGE
	            SET_BIT(MCUCSR_REG,6);
	#else    #error	"Invalid Sensing Mode Choice "
		    
		
	#endif
	
	/*        DISABLE INTERUPTS              */
	       CLR_BIT(GICR_REG,6);
		   CLR_BIT(GICR_REG,5);
		   CLR_BIT(GICR_REG,7);
		   
	/*        CLEAR INTERUPT FLAG OF EXT2             */
	       CLR_BIT(GIFR_REG,5);
}
void	EXT2_voidEnable(void)
{
    	GIE_voidEnable();
	    SET_BIT(GICR_REG,5);
	
}
void	EXT2_voidDisable(void)
{
	    CLR_BIT(GICR_REG,5);
}

void	EXT0_voidCallBack(void(*COPY_PF)(void))
{
	Call_Back_0= COPY_PF ;
}
void	EXT1_voidCallBack(void(*COPY_PF)(void))
{
	Call_Back_1= COPY_PF ;
}
void	EXT2_voidCallBack(void(*COPY_PF)(void))
{
	Call_Back_2= COPY_PF ;
}


void	__vector_1(void)
{
	Call_Back_0();
}
void	__vector_2(void)
{
	Call_Back_1();
}
void	__vector_3(void)
{
	Call_Back_2();
}