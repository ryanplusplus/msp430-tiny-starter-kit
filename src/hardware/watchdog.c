/*!
 * @file
 * @brief
 */

#include "watchdog.h"

enum {
  kick_period_msec = 10
};

static tiny_timer_t timer;

static void kick(void* context)
{
  (void)context;
}

void watchdog_init(tiny_timer_group_t* timer_group)
{
  tiny_timer_start_periodic(timer_group, &timer, kick_period_msec, NULL, kick);
}
