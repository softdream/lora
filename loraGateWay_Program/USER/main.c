#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include <string.h>
#include "configuration.h"


 int main(void)
 {	
	uint8_t str[7] = { 'h', 'e', 'l', 'l', 'o', '\r', '\n' };	
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_Configuration();// �����ж����ȼ�����
	uart_init(115200);	 //���ڳ�ʼ��Ϊ9600
	USART2_Init( 115200 ); // ���� 2 ��ʼ��
	LED_Indicator1();
	LED_Indicator2();
	
	//printf( "Program begins ...\r\n" );

	
	while(1){
		if( recvFinished2 == 1 ){ 
			recvFinished2 = 0;
			//printf( "%s", recvBuff2 );
		//	printf( "length = %d\r\n", recvLength2 );
			uart1SendStr( recvBuff2, recvLength2 );
			memset(recvBuff2, 0, sizeof( recvBuff2 ));
			recvLength2 = 0;
		}
		if( recvFinished == 1 ){
			
			recvFinished = 0;
			uart2SendStr( recvBuff, recvLength );
			memset( recvBuff, 0, sizeof( recvBuff ) );
			recvLength = 0;
			
		}
	/*	delay_ms( 4000 );
		delay_ms( 4000 );
		delay_ms( 4000 );
		uart1SendStr( str, 7 );*/

	}
	 
	return 0;
}


