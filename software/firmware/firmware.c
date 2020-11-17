#include "stdlib.h"
#include "system.h"
#include "periphs.h"
#include "iob-uart.h"
#include "time.h"

int main()
{
  srand(time(NULL));
  uart_init(UART_BASE,FREQ/BAUD);  
  int i=0;
  int n=0;
  int max=0;
  
  for(i=0;i<100;i++){
  	n=rand();
  	if(n>max) 
  	  max=n; 
  	uart_printf("%d\n",n);		
  } 
  uart_printf("Maximum number generated was %d\n",max);
  return 0;
}

