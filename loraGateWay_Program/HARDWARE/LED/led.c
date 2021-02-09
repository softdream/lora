#include "led.h"


void LED_Indicator1(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB端口时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;				 //PB.13 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIO
	GPIO_SetBits(GPIOB, GPIO_Pin_0);						 //PB13 输出低
	GPIO_SetBits(GPIOB, GPIO_Pin_1);						 //PB13 输出低
}

void LED_Indicator2(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PB端口时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;				 //PB.13 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIO
	GPIO_SetBits(GPIOA, GPIO_Pin_4);						 //PB13 输出低
	GPIO_SetBits(GPIOA, GPIO_Pin_5);						 //PB13 输出低
	GPIO_SetBits(GPIOA, GPIO_Pin_6);						 //PB13 输出低
	GPIO_SetBits(GPIOA, GPIO_Pin_7);						 //PB13 输出低
	
	
}
 
