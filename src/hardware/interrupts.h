/*!
 * @file
 * @brief
 */

#ifndef interrupts_h
#define interrupts_h

#include <msp430.h>
#include <stdint.h>

static inline void interrupts_disable(void)
{
  __disable_interrupt();
}

static inline void interrupts_enable(void)
{
  __enable_interrupt();
}

static inline uint8_t interrupts_save(void)
{
  return __get_interrupt_state();
}

static inline void interrupts_restore(uint8_t state)
{
  __set_interrupt_state(state);
}

#define interrupts_critical_section(...) \
  do {                                   \
    uint8_t state = interrupts_save();   \
    __VA_ARGS__                          \
    interrupts_restore(state);           \
  } while(0)

#endif
