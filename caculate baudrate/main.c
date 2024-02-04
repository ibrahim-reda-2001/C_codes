#include<stdio.h>
// this function return number of ones in digit number 
typedef unsigned int u32;
#define USARTDIV(baudrate,clock)               (u32)(clock/(16*baudrate))
#define USARTDIV_Mul100(baudrate,clock)        (u32)((clock*25)/(4*baudrate))
#define Mantissa_Mul100(baudrate,clock)        (u32)(USARTDIV(baudrate,clock)*100)
#define Mantissa(baudrate,clock)               (u32)(USARTDIV(baudrate,clock))
#define Div_Fraction(baudrate,clock)           (u32)(((USARTDIV_Mul100(baudrate,clock)-100*USARTDIV(baudrate,clock))*16)/100)
#define UART_BRR_Register(baudrate,clock)      ((Mantissa(baudrate,clock)) <<4)|(Div_Fraction(baudrate,clock)&0xf)


int main(void){
	
	u32 DIV= USARTDIV(115200,36000000) ;
	u32 MANT= Mantissa(115200,36000000) ;
	u32 Frac = Div_Fraction(115200,36000000) ;
	u32 BRR= UART_BRR_Register(115200,36000000) ;

printf(" DIV=%d   MANT=%d  fraction=%d BRR=%d \n",DIV,MANT,Frac,BRR);
	
	
	
return 0;}