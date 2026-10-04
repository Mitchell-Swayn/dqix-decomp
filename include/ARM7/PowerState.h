#ifndef ARM7_POWER_STATE_H
#define ARM7_POWER_STATE_H

/* The receive slots and operation word also have an observed interior view,
 * beginning four bytes after the initialized flag. Both names denote one state. */
typedef struct {unsigned short slots[16];unsigned int operation;} PowerRequestState;
typedef char PowerRequestStateSizeCheck[sizeof(PowerRequestState)==36?1:-1];
typedef struct {
 unsigned int initialized;
 PowerRequestState request;
} PowerState;
typedef char PowerStateSizeCheck[sizeof(PowerState)==40?1:-1];
extern PowerState ARM7_PowerState;
extern PowerRequestState ARM7_PowerRequest;
#endif
