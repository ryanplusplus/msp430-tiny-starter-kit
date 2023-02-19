/*!
 * @file
 * @brief
 */

#ifndef interrupts_h
#define interrupts_h

#include <stdint.h>

static inline void interrupts_disable(void)
{
}

static inline void interrupts_enable(void)
{
}

static inline void interrupts_wait_for_interrupt(void)
{
}

static inline uint8_t interrupts_save(void)
{
  return 0;
}

static inline void interrupts_restore(uint8_t state)
{
  (void)state;
}

#define interrupts_critical_section(...) \
  do {                                   \
    uint8_t state = interrupts_save();   \
    __VA_ARGS__                          \
    interrupts_restore(state);           \
  } while(0)

#endif
