#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#include "flash.h"

extern uint8_t recvCount;
extern uint8_t recvBuff[128];
extern uint8_t recvFinished;
extern uint8_t recvCount2;
extern uint8_t recvBuff2[128];
extern uint8_t recvFinished2;

extern int recvLength;
extern int recvLength2;

//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart_init(u32 bound);
void USART2_Init(u32 Baud);

void uart1SendStr(unsigned char *buff, int length);
void uart2SendStr( unsigned char *buff, int length );

void USART2_IRQHandler(void);
#endif


