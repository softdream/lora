#ifndef __CONFIGURATION_H_
#define __CONFIGURATION_H_

#include "usart.h"
#include "delay.h"
#include "sys.h"

uint8_t sendEnterATMode(void);
uint8_t sendATForTest(void);
uint8_t sendATI(void);
uint8_t sendATZ(void);
uint8_t sendATR(void);
uint8_t sendATT(void);

uint8_t sendAT_ID(void);
uint8_t sendAT_CSQ(void);
uint8_t sendAT_ADDR(void);
uint8_t sendAT_MADDR(void);
uint8_t sendAT_TFREQ(void);
uint8_t sendAT_RFREQ(void);
uint8_t sendAT_FREQA(void);
uint8_t sendAT_FREQB(void);

uint8_t sendAT_Net( int x );
uint8_t sendAT_BRATE( int x );
uint8_t sendAT_TYPE( int x );

uint8_t sendATTSF( uint8_t rate );

#endif

