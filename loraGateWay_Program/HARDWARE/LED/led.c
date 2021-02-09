#include "led.h"


void LED_Indicator1(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;				 //PB.13 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIO
	GPIO_SetBits(GPIOB, GPIO_Pin_0);						 //PB13 �����
	GPIO_SetBits(GPIOB, GPIO_Pin_1);						 //PB13 �����
}

void LED_Indicator2(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PB�˿�ʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;				 //PB.13 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIO
	GPIO_SetBits(GPIOA, GPIO_Pin_4);						 //PB13 �����
	GPIO_SetBits(GPIOA, GPIO_Pin_5);						 //PB13 �����
	GPIO_SetBits(GPIOA, GPIO_Pin_6);						 //PB13 �����
	GPIO_SetBits(GPIOA, GPIO_Pin_7);						 //PB13 �����
	
	
}
 
