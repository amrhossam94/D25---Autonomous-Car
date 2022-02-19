#ifndef		TIM_PRIVATE_H
#define		TIM_PRIVATE_H


#define		TCCR1A_REG		*((volatile u8 *)0x4F)
#define		TCCR1B_REG		*((volatile u8 *)0x4E)

#define		TCNT1_REG		*((volatile u16 *)0x4C)

#define		OCR1A_REG		*((volatile u16 *)0x4A)
#define		OCR1B_REG		*((volatile u16 *)0x48)

#define		ICR1L_REG		*((volatile u8 *)0x46)
#define		ICR1H_REG		*((volatile u8 *)0x47)

#define		TIMSK_REG		*((volatile u8 *)0x59) 
#define		TIFR_REG		*((volatile u8 *)0x58)	

						    
#endif