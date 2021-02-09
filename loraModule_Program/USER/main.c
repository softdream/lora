#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include <string.h>
#include "configuration.h"


 int main(void)
 {	
	uint8_t str[7] = { 'h', 'e', 'l', 'l', '0', '\r', '\n' };	
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_Configuration();// �����ж����ȼ�����
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	USART2_Init( 9600 ); // ���� 2 ��ʼ��
	//timer_config();
	
	
	LED_Init();
	LED_Init2();
	
	//printf( "Program begins ...\r\n" );

	
	while(1){
		if( recvFinished2 == 1 ){ 
			recvFinished2 = 0;
			//printf( "%s\r\n", recvBuff2 );
			//printf( "length = %d\r\n", recvLength2 );
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
		
	/*	uart1SendStr(str, 7);
		delay_ms( 4000 );
		delay_ms( 4000 );
		delay_ms( 4000 );*/
		
	}
	 
	return 0;
}


