#ifndef __FLASH_H_
#define __FLASH_H_

#include "stm32f10x_flash.h"

#define FLASH_PAGE_SIZE			(1 * 1024)		/* h?2k */

typedef unsigned char INT8U;
typedef unsigned short INT16U;
typedef unsigned long INT32U;
typedef signed short INT16S;
typedef unsigned long INT32U;
typedef signed long INT32S;

union ulong_type{
	INT32U hex;
	INT16U ss[2];
	INT8U bb[4];
};


void flash_rd(INT32U addr, INT8U *buf, INT32U len);
void flash_wr(INT32U addr, INT8U *buf, INT32U len);
void flash_erase_page(INT32U addr);
void falsh_erase_len(INT32U addr, INT32U len);

#endif

