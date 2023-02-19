/*!
 * @file
 * @brief 1 msec tick using Timer0 A0.
 */

#ifndef system_tick_h
#define system_tick_h

#include "i_tiny_time_source.h"

i_tiny_time_source_t* system_tick_init(void);

#endif
