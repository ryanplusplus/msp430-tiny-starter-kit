/*!
 * @file
 * @brief
 */

#include <msp430.h>
#include "watchdog.h"

enum {
  kick_period_msec = 10
};

static tiny_timer_t timer;

static inline void halt_watchdog(void)
{
  WDTCTL = WDTPW | WDTHOLD;
}

static inline void reset_watchdog(void)
{
  // ACLK ~= 12 KHz
  // 250 msec assumes 32 KHz, so this is ~500 msec
  WDTCTL = WDT_ARST_250;
}

static void kick(void* context)
{
  (void)context;
  reset_watchdog();
}

void watchdog_init(tiny_timer_group_t* timer_group)
{
  halt_watchdog();
  reset_watchdog();

  tiny_timer_start_periodic(timer_group, &timer, kick_period_msec, NULL, kick);
}
