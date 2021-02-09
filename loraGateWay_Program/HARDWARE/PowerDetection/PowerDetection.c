#include "PowerDetection.h"

void powerDetection_Init( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 						 
	/* PC10 */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  // 设置为下拉输入，默认为低电平
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}              


uint8_t powerDetection( void )
{
	return GPIO_ReadInputDataBit( GPIOC, GPIO_Pin_10 ); // 返回引脚的高低电平状态
}


