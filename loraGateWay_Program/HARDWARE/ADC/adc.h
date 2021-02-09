#ifndef __ADC_H_
#define __ADC_H_

#include "stm32f10x_adc.h"

void adc_init(void);

uint16_t get_adc_channel_0( void );
uint16_t get_adc_channel_1( void );
uint16_t get_adc_channel_2( void );
float get_voltage( void );

#endif

