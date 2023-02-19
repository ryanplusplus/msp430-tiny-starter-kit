/*!
 * @file
 * @brief
 */

#ifndef clock_h
#define clock_h

#include <msp430.h>

#define clock_frequency 16000000UL

static inline void clock_init(void)
{
  DCOCTL = 0;
  BCSCTL1 = CALBC1_16MHZ;
  DCOCTL = CALDCO_16MHZ;
}

#endif
