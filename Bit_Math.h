#ifndef		BIT_MATH_H
#define		BIT_MATH_H

#define		SET_BIT(REG,BIT_NUM)		REG|=	(1<<BIT_NUM)
#define		CLR_BIT(REG,BIT_NUM)		REG&= 	~(1<<BIT_NUM)
#define		TOG_BIT(REG,BIT_NUM)		REG^=	(1<<BIT_NUM)
#define		GET_BIT(REG,BIT_NUM)		1&(REG>>BIT_NUM)
#define		CIR_BIT_L(REG)				GET_BIT(REG,7)|(REG<<1)
#define		CIR_BIT_R(REG)				(GET_BIT(REG,0)<<7)|(REG>>1)
#define		CLR_NIB_L(REG)				REG&=0xf0
#define		CLR_NIB_H(REG)				REG&=0x0f
#define		SET_NIB_L(REG)				REG|=0x0f
#define		SET_NIB_H(REG)				REG|=0xf0
#define		SET_PORT(REG,Value)			REG=Value


#endif