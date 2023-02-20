/*!
 * @file
 * @brief
 */

#ifndef reset_h
#define reset_h

#include <msp430.h>

static inline void reset(void)
{
  WDTCTL |= WDTHOLD;
}

#endif
