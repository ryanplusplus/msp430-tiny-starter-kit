/*!
 * @file
 * @brief
 */

#ifndef clock_h
#define clock_h

#include <msp430.h>

#define clock_aclk_frequency 12000
#define clock_smclk_frequency 16000000UL

static inline void clock_init(void)
{
  // DCO 16 MHz
  DCOCTL = 0;
  BCSCTL1 = CALBC1_16MHZ;
  DCOCTL = CALDCO_16MHZ;

  // ACLK VLO (12 KHz
  BCSCTL3 = LFXT1S_2;
}

#endif
