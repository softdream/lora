#include "sys.h"
#include "usart.h"	  
#include "led.h"

int Time2_cnt = 0;

#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
/*int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;
}*/

//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
	while((USART2->SR&0X40)==0);//循环发送,直到发送完毕   
    USART2->DR = (u8) ch;      
	return ch;
}
#endif 

uint8_t recvBuff[ 128 ];
uint8_t recvCount = 0;
uint8_t recvFinished	= 0;
uint8_t recvBuff2[ 128 ];
uint8_t recvCount2 = 0;
uint8_t recvFinished2	= 0;

int recvLength = 0;
int recvLength2 = 0;

//初始化IO 串口1 
//bound:波特率
void uart_init(u32 bound){
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//??USART1,GPIOA??
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//??????
  GPIO_Init(GPIOA, &GPIO_InitStructure);//???GPIOA.9
   
  //USART1_RX	  GPIOA.10???
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//????
  GPIO_Init(GPIOA, &GPIO_InitStructure);//???GPIOA.10  

  //Usart1 NVIC ??
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2 ;//?????3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//????3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ????
	NVIC_Init(&NVIC_InitStructure);	//??????????VIC???
  
	USART_InitStructure.USART_BaudRate = bound;//?????
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//???8?????
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//?????
	USART_InitStructure.USART_Parity = USART_Parity_No;//??????
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//????????
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//????

  USART_Init(USART1, &USART_InitStructure); //?????1
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//????????
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE); //开启串口1接收空闲中断
  USART_Cmd(USART1, ENABLE);                    //????1 
}


void USART2_Init(u32 Baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//??GPIO?????2??
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	//????2??
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//PA2:??
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//??????
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PA3:??
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//????
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//??????
	USART_InitStructure.USART_BaudRate = Baud;//???
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_Init(USART2, &USART_InitStructure);
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//????,????????????
	USART_ITConfig(USART2, USART_IT_IDLE, ENABLE); //开启串口2接收空闲中断
	
  USART_Cmd(USART2, ENABLE);                    //???? 
	
	//NVIC??????????
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//?????3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//????3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ????
	NVIC_Init(&NVIC_InitStructure);	//??????????NVIC???

}

void timer_config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	/* Resets the TIM2 */
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 10;//????1ms???
	TIM_TimeBaseStructure.TIM_Prescaler = 7199;

	//TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);    

	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	/* Enables the TIM2 counter */
	TIM_Cmd(TIM2, ENABLE);

	/* Enables the TIM2 Capture Compare channel 1 Interrupt source */
	TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE );
	
	//NVIC
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		
	NVIC_Init(&NVIC_InitStructure);
}


void uart1SendStr( unsigned char *buff, int length )
{
	int i;
	for( i = 0; i < length; i ++ ){
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) ==RESET);
		USART_SendData(USART1, buff[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC));
	}
}

void uart2SendStr( unsigned char *buff, int length )
{
	int i;
	for( i = 0; i < length; i ++ ){
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) ==RESET);
		USART_SendData(USART2, buff[i]);
		while(USART_GetFlagStatus(USART2, USART_FLAG_TC));
	}
}


void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	uint8_t temp;
	if( USART_GetFlagStatus(USART1, USART_FLAG_ORE) != RESET ){
		USART_ClearITPendingBit(USART1, USART_FLAG_ORE);
		USART_ReceiveData(USART1); 
	}
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET){
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		temp = USART_ReceiveData(USART1);
		if( recvCount > 128 ){
			recvCount = 0;
		}
		recvBuff[recvCount ++] = temp;
	}
	if(USART_GetFlagStatus(USART1, USART_FLAG_IDLE) != RESET){
		USART_ClearITPendingBit(USART1, USART_FLAG_IDLE);
		USART_ReceiveData(USART1); 
		recvFinished = 1;
		
		recvLength = recvCount;
		recvCount = 0;
	}	
} 

 
void USART2_IRQHandler(void)                	//串口2中断服务程序
{
	uint8_t temp;
	if( USART_GetFlagStatus(USART2, USART_FLAG_ORE) != RESET ){
		USART_ClearITPendingBit(USART2, USART_FLAG_ORE);
		USART_ReceiveData(USART2); 
	}
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET){
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
		temp = USART_ReceiveData(USART2);
		if( recvCount2 > 128 ){
			recvCount2 = 0;
		}
		recvBuff2[recvCount2 ++] = temp;
	}
	if(USART_GetFlagStatus(USART2, USART_FLAG_IDLE) != RESET){
		USART_ClearITPendingBit(USART2, USART_FLAG_IDLE);
		USART_ReceiveData(USART2); 
		recvFinished2 = 1;
		
		recvLength2 = recvCount2;
		recvCount2 = 0;
	}	
}



/*void TIM2_IRQHandler(void)
{
	//printf( "timer\r\n" );
	if( TIM_GetITStatus( TIM2, TIM_IT_Update ) == SET ){
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		if( Time2_cnt < 100 ){
			Time2_cnt ++ ;
		}
		if( Time2_cnt > 3 ){
			TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE );
			recvFinished2 = 1;//接收完成标志位置1
			recvLength2 = recvCount2;//复制接收的数据长度
			recvCount2 = 0;//清零接收的数据个数
		}
	}
}*/


