#ifndef ARM7_POWER_STATE_H
#define ARM7_POWER_STATE_H

typedef struct {
 unsigned int initialized;
 unsigned short slots[16];
 unsigned int operation;
} PowerState;
typedef char PowerStateSizeCheck[sizeof(PowerState)==40?1:-1];

extern PowerState ARM7_PowerState;
#endif
