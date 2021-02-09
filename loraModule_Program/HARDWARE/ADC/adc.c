#include "adc.h"

 /* adc 初始化 */
void adc_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;      
    ADC_InitTypeDef ADC_InitStructure;          
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);         // GPIOA
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);          // ADC1
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);    // 采样频率：72/6 = 12Mhz         
    
		/* 通道 0 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;                           //PA0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;                       //模拟输入
    GPIO_Init(GPIOA,&GPIO_InitStructure);                          
 	  
	  /* 通道 1 */   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; // PA1
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		/* 通道 2 */   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; // PA2
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
    ADC_DeInit(ADC1);                            // 复位adc1
    
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                  //
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;                       //单通道模式
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;                 //单次转化模式
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; //软件触发
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;              //数据右对齐
    ADC_InitStructure.ADC_NbrOfChannel = 1;                             //顺序进行规则转化的adc通道
    ADC_Init(ADC1,&ADC_InitStructure);                                  //???ADC1
    
		ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5 );
		ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_239Cycles5 );
		ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_239Cycles5 );
		
    ADC_Cmd(ADC1,ENABLE);                        //使能ADC1
		
    ADC_ResetCalibration(ADC1);                  //使能复位校准adc1
    while(ADC_GetResetCalibrationStatus(ADC1));  //等待复位校准结束
    ADC_StartCalibration(ADC1);                  //开始adc校准
    while(ADC_GetCalibrationStatus(ADC1));       
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);       //启动转换
}

/* 得到通道 0 的数据 */
uint16_t get_adc_channel_0(void)
{
    ADC_RegularChannelConfig(ADC1,ADC_Channel_0, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);          
    while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));   
    return ADC_GetConversionValue(ADC1);          
}

/* 得到通道 1 的数据 */
uint16_t get_adc_channel_1(void)
{
    ADC_RegularChannelConfig(ADC1,ADC_Channel_2, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);          
    while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));   
    return ADC_GetConversionValue(ADC1);          
}

/* 得到通道 2 的数据 */
uint16_t get_adc_channel_2(void)
{
    ADC_RegularChannelConfig(ADC1,ADC_Channel_1, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);          
    while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));   
    return ADC_GetConversionValue(ADC1);          
}

/* 得到电压值 */
float get_voltage( void )
{
	 return ( (float)get_adc_channel_0()*3300/4096 ); // 电压值 mV
}

/* 麦克风的处理函数 */

/* 光敏电阻的处理函数 */


