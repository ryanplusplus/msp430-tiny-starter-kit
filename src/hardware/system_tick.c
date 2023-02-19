/*!
 * @file
 * @brief
 */

#include "system_tick.h"

static volatile tiny_time_source_ticks_t current_ticks;

// ISR(TCB0_INT_vect)
// {
//   current_ticks++;
// }

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

  // do some init stuff

  return &instance;
}
