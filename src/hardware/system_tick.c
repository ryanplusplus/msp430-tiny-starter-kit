/*!
 * @file
 * @brief
 */

#include <msp430.h>
#include "clock.h"
#include "system_tick.h"

static volatile tiny_time_source_ticks_t current_ticks;

__attribute__((interrupt(TIMER0_A0_VECTOR))) void system_tick_isr(void)
{
  current_ticks++;
}

static tiny_time_source_ticks_t ticks(i_tiny_time_source_t* self)
{
  (void)self;

  tiny_time_source_ticks_t previous;
  tiny_time_source_ticks_t current = current_ticks;

  do {
    previous = current;
    current = current_ticks;
  } while(current != previous);

  return current;
}

static const i_tiny_time_source_api_t api = { ticks };

i_tiny_time_source_t* system_tick_init(void)
{
  static i_tiny_time_source_t instance = { &api };

  // Count up to CCR0 and select SMCLK
  TA0CTL = TASSEL_2 | MC_1;

  // 1 msec tick
  TA0CCR0 = (clock_smclk_frequency / 1000) - 1;

  // Enable capture/compare interrupt
  TA0CCTL0 = CCIE;

  return &instance;
}
