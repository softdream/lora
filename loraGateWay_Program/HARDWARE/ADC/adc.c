#include "adc.h"

 /* adc ��ʼ�� */
void adc_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;      
    ADC_InitTypeDef ADC_InitStructure;          
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);         // GPIOA
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);          // ADC1
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);    // ����Ƶ�ʣ�72/6 = 12Mhz         
    
		/* ͨ�� 0 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;                           //PA0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;                       //ģ������
    GPIO_Init(GPIOA,&GPIO_InitStructure);                          
 	  
	  /* ͨ�� 1 */   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; // PA1
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		/* ͨ�� 2 */   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; // PA2
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
    ADC_DeInit(ADC1);                            // ��λadc1
    
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                  //
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;                       //��ͨ��ģʽ
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;                 //����ת��ģʽ
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; //�������
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;              //�����Ҷ���
    ADC_InitStructure.ADC_NbrOfChannel = 1;                             //˳����й���ת����adcͨ��
    ADC_Init(ADC1,&ADC_InitStructure);                                  //???ADC1
    
		ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5 );
		ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_239Cycles5 );
		ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_239Cycles5 );
		
    ADC_Cmd(ADC1,ENABLE);                        //ʹ��ADC1
		
    ADC_ResetCalibration(ADC1);                  //ʹ�ܸ�λУ׼adc1
    while(ADC_GetResetCalibrationStatus(ADC1));  //�ȴ���λУ׼����
    ADC_StartCalibration(ADC1);                  //��ʼadcУ׼
    while(ADC_GetCalibrationStatus(ADC1));       
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);       //����ת��
}

/* �õ�ͨ�� 0 ������ */
uint16_t get_adc_channel_0(void)
{
    ADC_RegularChannelConfig(ADC1,ADC_Channel_0, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);          
    while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));   
    return ADC_GetConversionValue(ADC1);          
}

/* �õ�ͨ�� 1 ������ */
uint16_t get_adc_channel_1(void)
{
    ADC_RegularChannelConfig(ADC1,ADC_Channel_2, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);          
    while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));   
    return ADC_GetConversionValue(ADC1);          
}

/* �õ�ͨ�� 2 ������ */
uint16_t get_adc_channel_2(void)
{
    ADC_RegularChannelConfig(ADC1,ADC_Channel_1, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConvCmd(ADC1,ENABLE);          
    while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));   
    return ADC_GetConversionValue(ADC1);          
}

/* �õ���ѹֵ */
float get_voltage( void )
{
	 return ( (float)get_adc_channel_0()*3300/4096 ); // ��ѹֵ mV
}

/* ��˷�Ĵ����� */

/* ��������Ĵ����� */


