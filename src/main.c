/*!
 * @file
 * @brief
 */

#include "interrupts.h"
#include "system_tick.h"
#include "heartbeat.h"
#include "tiny_timer.h"
#include "watchdog.h"
#include "clock.h"
#include "tiny_utils.h"

#include <msp430.h>

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output

	volatile unsigned int i;		// volatile to prevent optimization

	while(1)
	{
		P1OUT ^= 0x01;				// toggle P1.0
		for(i=10000; i>0; i--);     // delay
	}

  // static tiny_timer_group_t timer_group;

  // WDTCTL = WDTPW | WDTHOLD;

  // // P1SEL &= ~0x01;
  // P1DIR |= 0x01;

  // while(1) {
  //   P1OUT ^= 0x01;
  // }

  // interrupts_disable();
  // {
  //   clock_init();
  //   tiny_timer_group_init(&timer_group, system_tick_init());
  //   watchdog_init(&timer_group);
  //   heartbeat_init(&timer_group);
  // }
  // interrupts_enable();

  // while(1) {
  //   if(tiny_timer_group_run(&timer_group)) {
  //     interrupts_wait_for_interrupt();
  //   }
  // }
}
