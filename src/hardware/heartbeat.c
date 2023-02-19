/*!
 * @file
 * @brief
 */

#include <msp430.h>
#include <stddef.h>
#include "heartbeat.h"

enum {
  half_period_in_msec = 500
};

static tiny_timer_t timer;

static void blink(void* context)
{
  P1OUT ^= 0x01;
  (void)context;
}

void heartbeat_init(tiny_timer_group_t* timer_group)
{
  P1DIR |= 0x01;
  tiny_timer_start_periodic(timer_group, &timer, half_period_in_msec, NULL, blink);
}
