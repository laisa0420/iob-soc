//#include "stdlib.h"
#include "system.h"
#include "periphs.h"
#include "iob-uart.h"
#include "iob_timer.h"

int main()
{
  
  unsigned long long elapsed;
  unsigned int elapsedu;

  timer_reset(TIMER_BASE);
  //read current timer count, compute elapsed time
  //elapsed=timer_get_count(TIMER_BASE);
  //elapsedu=timer_time_us(TIMER_BASE);

  //init uart 
  uart_init(UART_BASE,FREQ/BAUD);   
  uart_printf("\n\n\nHello world!\n\n\n");
  uart_txwait();
  elapsed=timer_get_count(TIMER_BASE);
  elapsedu=timer_time_us(TIMER_BASE);
  uart_printf("\nExecution time: %d clocks in %dus @%dMHz\n\n", (unsigned int)elapsed, elapsedu, FREQ/1000000);
  uart_txwait();
  return 0;
  //char *a = malloc(10);
  //free(a);
}
