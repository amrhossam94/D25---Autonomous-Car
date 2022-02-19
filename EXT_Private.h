#ifndef		EXT_PRIVATE_H
#define		EXT_PRIVATE_H


#define		 MCUCR_REG		*((volatile u8 *)0x55)
#define		 MCUCSR_REG		*((volatile u8 *)0x54)
#define		 GICR_REG		*((volatile u8 *)0x5B)
#define		 GIFR_REG		*((volatile u8 *)0x5A)


#define  LOW_LEVEL				0
#define  ANY_EDGE				1	
#define  FALLING_EDGE			2
#define  RISING_EDGE			3


#endif