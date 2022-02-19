#ifndef		EXT_INTERFACE_H
#define		EXT_INTERFACE_H


void	EXT0_voidCallBack(void(*COPY_PF)(void));


void	__vector_1(void) __attribute__((signal,used));




void	EXT0_voidInt(void);
void	EXT0_voidEnable(void);
void	EXT0_voidDisable(void);







#endif