#include "configuration.h"
#include <string.h>

uint8_t sendEnterATMode(void)
{
	unsigned char str[3] = { '+', '+', '+' };
	uart1SendStr( str, 3 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	//memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send +++ command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send +++ command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendATForTest(void)
{
	unsigned char str[4] = {'A', 'T', '\r', '\n'};
	uart1SendStr( str, 4 );
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	//memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send AT command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send AT command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendATI(void)
{
	unsigned char str[5] = {'A', 'T', 'I', '\r', '\n'};
	unsigned char temp[6];
	
	uart1SendStr( str, 5 );
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	
	memcpy( temp, recvBuff, 6 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( !strcmp( (char*)temp, "\r\n+ATI" ) ){
		printf( "send ATI command OK\r\n" );
		return 1;
	}
	else {
		printf( "send ATI command ERROR\r\n" );
		return 0;	
	}
}

uint8_t sendATZ(void)
{
	unsigned char str[5] = {'A', 'T', 'Z', '\r', '\n'};
	uart1SendStr( str, 5 );
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	//memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send ATZ command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send ATZ command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendATR(void)
{
	unsigned char str[5] = {'A', 'T', 'R', '\r', '\n'};
	uart1SendStr( str, 5 );
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	//memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send ATR command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send ATR command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendATT(void)
{
	unsigned char str[5] = {'A', 'T', 'T', '\r', '\n'};
	uart1SendStr( str, 5 );
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	//memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send ATT command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send ATT command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendAT_ID(void)
{
	unsigned char str[8] = {'A', 'T', '+', 'I', 'D', '?', '\r', '\n'};
	unsigned char temp[5];
	
	uart1SendStr( str, 8 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	memcpy( temp, recvBuff, 5 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	printf( "%s", temp );
	if( !strcmp( (char*)temp, "\r\n+ID" ) ){
		printf( "send AT+ID? command OK\r\n" );
		return 1;
	}
	else {
		printf( "send AT+ID? command ERROR\r\n" );
		return 0;	
	}
}

uint8_t sendAT_CSQ(void)
{
	unsigned char str[9] = {'A', 'T', '+', 'C', 'S', 'Q', '?', '\r', '\n'};
	unsigned char temp[6];
	
	uart1SendStr( str, 9 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	memcpy( temp, recvBuff, 6 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( !strcmp( (char*)temp, "\r\n+CSQ" ) ){
		printf( "send AT+CSQ? command OK\r\n" );
		return 1;
	}
	else {
		printf( "send AT+CSQ? command ERROR\r\n" );
		return 0;	
	}
}

uint8_t sendAT_ADDR(void)
{
	unsigned char str[10] = {'A', 'T', '+', 'A', 'D', 'D', 'R', '?', '\r', '\n'};
	unsigned char temp[7];
	
	uart1SendStr( str, 10 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	memcpy( temp, recvBuff, 7 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( !strcmp( (char*)temp, "\r\n+ADDR" ) ){
		printf( "send AT+ADDR? command OK\r\n" );
		return 1;
	}
	else {
		printf( "send AT+ADDR? command ERROR\r\n" );
		return 0;	
	}
}

uint8_t sendAT_MADDR(void)
{
	unsigned char str[11] = {'A', 'T', '+', 'M', 'A', 'D', 'D', 'R', '?', '\r', '\n'};
	unsigned char temp[8];
	
	uart1SendStr( str, 11 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	memcpy( temp, recvBuff, 8 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( !strcmp( (char*)temp, "\r\n+MADDR" ) ){
		printf( "send AT+MADDR? command OK\r\n" );
		return 1;
	}
	else {
		printf( "send AT+MADDR? command ERROR\r\n" );
		return 0;	
	}
}

uint8_t sendAT_TFREQ(void)
{
	unsigned char str[11] = {'A', 'T', '+', 'T', 'F', 'R', 'E', 'Q', '?', '\r', '\n'};
	unsigned char temp[8];
	
	uart1SendStr( str, 11 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	memcpy( temp, recvBuff, 8 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	
	printf( "%s", temp );
	if( !strcmp( (char*)temp, "\r\n+TFREQ" ) ){
		printf( "send AT+TFREQ? command OK\r\n" );
		return 1;
	}
	else {
		printf( "send AT+TFREQ? command ERROR\r\n" );
		return 0;	
	}
}

uint8_t sendAT_RFREQ(void)
{
	unsigned char str[11] = {'A', 'T', '+', 'R', 'F', 'R', 'E', 'Q', '?', '\r', '\n'};
	unsigned char temp[8];
	
	uart1SendStr( str, 11 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	memcpy( temp, recvBuff, 8 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	printf( "%s", temp );
	if( !strcmp( (char*)temp, "\r\n+RFREQ" ) ){
		printf( "send AT+RFREQ? command OK\r\n" );
		return 1;
	}
	else {
		printf( "send AT+RFREQ? command ERROR\r\n" );
		return 0;	
	}
}

uint8_t sendAT_FREQA(void)
{
	unsigned char str[11] = {'A', 'T', '+', 'F', 'R', 'E', 'Q', 'A', '?', '\r', '\n'};
	unsigned char temp[8];
	
	uart1SendStr( str, 11 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	memcpy( temp, recvBuff, 8 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( !strcmp( (char*)temp, "\r\n+FREQA" ) ){
		printf( "send AT+FREQA? command OK\r\n" );
		return 1;
	}
	else {
		printf( "send AT+FREQA? command ERROR\r\n" );
		return 0;	
	}
}

uint8_t sendAT_FREQB(void)
{
	unsigned char str[11] = {'A', 'T', '+', 'F', 'R', 'E', 'Q', 'B', '?', '\r', '\n'};
	unsigned char temp[8];
	
	uart1SendStr( str, 11 );
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	memcpy( temp, recvBuff, 8 );
	memset( recvBuff, 0, sizeof( recvBuff ) );
	
	if( !strcmp( (char*)temp, "\r\n+FREQB" ) ){
		printf( "send AT+FREQA? command OK\r\n" );
		return 1;
	}
	else {
		printf( "send AT+FREQA? command ERROB\r\n" );
		return 0;	
	}
}

uint8_t sendAT_Net( int x )
{
	unsigned char str1[11] = {'A', 'T', '+', 'N', 'E', 'T', '=', '0', '0', '\r', '\n'};
	unsigned char str2[11] = {'A', 'T', '+', 'N', 'E', 'T', '=', '0', '1', '\r', '\n'};

	if( x == 0 ){
		uart1SendStr( str1, 11 );
	}
	else if( x == 1 ){
		uart1SendStr( str2, 11 );
	}
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send AT+NET command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send AT+NET command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendAT_BRATE( int x )
{
	unsigned char str1[13] = {'A', 'T', '+', 'B', 'R', 'A', 'T', 'E', '=', '0', '3', '\r', '\n'};
	unsigned char str2[13] = {'A', 'T', '+', 'B', 'R', 'A', 'T', 'E', '=', '0', '4', '\r', '\n'};
	unsigned char str3[13] = {'A', 'T', '+', 'B', 'R', 'A', 'T', 'E', '=', '0', '7', '\r', '\n'};
	
	switch ( x ){
		case 3: uart1SendStr( str1, 13 );break;
		case 4: uart1SendStr( str2, 13 );break;
		case 7: uart1SendStr( str3, 13 );break;
		default: break;
	}
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send AT+NET command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send AT+NET command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendAT_TYPE( int x )
{
	unsigned char str1[12] = {'A', 'T', '+', 'T', 'Y', 'P', 'E', '=', '0', '0', '\r', '\n'};
	unsigned char str2[12] = {'A', 'T', '+', 'T', 'Y', 'P', 'E', '=', '0', '1', '\r', '\n'};
	unsigned char str3[12] = {'A', 'T', '+', 'T', 'Y', 'P', 'E', '=', '0', '2', '\r', '\n'};
	unsigned char str4[12] = {'A', 'T', '+', 'T', 'Y', 'P', 'E', '=', '0', '3', '\r', '\n'};
	unsigned char str5[12] = {'A', 'T', '+', 'T', 'Y', 'P', 'E', '=', '0', '4', '\r', '\n'};
	
	switch ( x ){
		case 0: uart1SendStr( str1, 13 );break;
		case 1: uart1SendStr( str2, 13 );break;
		case 2: uart1SendStr( str3, 13 );break;
		case 3: uart1SendStr( str4, 13 );break;
		case 4: uart1SendStr( str5, 13 );break;
		default: break;
	}
	
	while( recvFinished != 1 );
	recvFinished = 0;
	
	printf( "%s", recvBuff );
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send AT+NET command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send AT+NET command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendATTSF( uint8_t rate )
{
	unsigned char str1[11] = { 'A', 'T', '+', 'T', 'S', 'F', '=', '0', 'C', '\r', '\n' };
	unsigned char str2[11] = { 'A', 'T', '+', 'T', 'S', 'F', '=', '0', '5', '\r', '\n' };
	unsigned char str3[11] = { 'A', 'T', '+', 'T', 'S', 'F', '=', '0', 'A', '\r', '\n' };
	
	switch( rate ){
		case 0x0C:{
			uart1SendStr( str1, 11 );
			break;
		}
		case 0x05:{
			uart1SendStr( str2, 11 );
			break;
		}
		case 0x0A:{
			uart1SendStr( str3, 11 );
			break;
		}
		default: break;
	}
	
	while( recvFinished != 1 );
	recvFinished = 0;
	printf( "%s", recvBuff );
	
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send AT+TSF command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send AT+TSF command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}

uint8_t sendATRSF( uint8_t rate )
{
	unsigned char str1[11] = { 'A', 'T', '+', 'R', 'S', 'F', '=', '0', 'C', '\r', '\n' };
	unsigned char str2[11] = { 'A', 'T', '+', 'R', 'S', 'F', '=', '0', '5', '\r', '\n' };
	unsigned char str3[11] = { 'A', 'T', '+', 'R', 'S', 'F', '=', '0', 'A', '\r', '\n' };
	
	switch( rate ){
		case 0x0C:{
			uart1SendStr( str1, 11 );
			break;
		}
		case 0x05:{
			uart1SendStr( str2, 11 );
			break;
		}
		case 0x0A:{
			uart1SendStr( str3, 11 );
			break;
		}
		default: break;
	}
	
	while( recvFinished != 1 );
	recvFinished = 0;
	printf( "%s", recvBuff );
	
	if( strcmp( (char*)recvBuff, "\r\nOK\r\n" ) == 0 ){
		printf( "send AT+RSF command Ok\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 1;
	}
	else {
		printf( "send AT+RSF command ERROR\r\n" );
		memset( recvBuff, 0, sizeof( recvBuff ) );
		return 0;
	}
}
