#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED1_ON GPIO_SetBits( GPIOA, GPIO_Pin_4 )
#define LED1_OFF GPIO_ResetBits(GPIOA, GPIO_Pin_4)

#define LED2_ON GPIO_SetBits( GPIOA, GPIO_Pin_5 )
#define LED2_OFF GPIO_ResetBits(GPIOA, GPIO_Pin_5)

#define LED3_ON GPIO_SetBits( GPIOA, GPIO_Pin_6 )
#define LED3_OFF GPIO_ResetBits(GPIOA, GPIO_Pin_6)

#define LED4_ON GPIO_SetBits( GPIOA, GPIO_Pin_7 )
#define LED4_OFF GPIO_ResetBits(GPIOA, GPIO_Pin_7)

void LED_Indicator1(void);//≥ı ºªØ

void LED_Indicator2(void);    


#endif
