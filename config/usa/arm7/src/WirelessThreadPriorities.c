/* Apply either stored three-priority set while IRQs and thread switching are
 * locked. The two service threads reverse order between these operations;
 * the middle priority belongs to the wireless driver thread. */
#pragma dont_inline on
#include "ThreadContext.h"
#include "Completion20261008/c18/b09/WirelessHelpers.h"
typedef struct {
    WirelessStateView state;
    unsigned int priorities[6];
} WirelessSchedulingState;
typedef char WirelessPriorityOffsetCheck[sizeof(WirelessStateView) == 0x578 ? 1 : -1];
// Original: arm7/mainram @ 0x027F8F5C; symbol: ARM7_WirelessState.
// Extended consumer view of existing storage; no data/BSS is defined here.
extern WirelessSchedulingState ARM7_WirelessSchedulingState;
// Original: arm7/wram @ 0x0380CBDC and 0x0380CC80; service-thread contexts.
extern ProcessorContext ARM7_WirelessServiceThreadA, ARM7_WirelessServiceThreadB;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern unsigned int ARM7_LockThreadSwitch(void);
extern unsigned int ARM7_UnlockThreadSwitch(void);
extern int ARM7_SetThreadPriority(ProcessorContext *, unsigned int);
extern ProcessorContext *ARM7_GetWirelessDriverThread(void);
// Original: arm7/mainram @ 0x027E0640; symbol: ARM7_ApplyWirelessThreadPrioritiesThreeToFive; size: 0x60.
void ARM7_ApplyWirelessThreadPrioritiesThreeToFive(void)
{
    int state = ARM7_DisableIRQInterrupts();
    ARM7_LockThreadSwitch();
    ARM7_SetThreadPriority(&ARM7_WirelessServiceThreadA, ARM7_WirelessSchedulingState.priorities[5]);
    ARM7_SetThreadPriority(ARM7_GetWirelessDriverThread(), ARM7_WirelessSchedulingState.priorities[4]);
    ARM7_SetThreadPriority(&ARM7_WirelessServiceThreadB, ARM7_WirelessSchedulingState.priorities[3]);
    ARM7_UnlockThreadSwitch();
    ARM7_SetIRQInterruptState(state);
}
// Original: arm7/mainram @ 0x027E06A0; symbol: ARM7_ApplyWirelessThreadPrioritiesZeroToTwo; size: 0x60.
void ARM7_ApplyWirelessThreadPrioritiesZeroToTwo(void)
{
    int state = ARM7_DisableIRQInterrupts();
    ARM7_LockThreadSwitch();
    ARM7_SetThreadPriority(&ARM7_WirelessServiceThreadB, ARM7_WirelessSchedulingState.priorities[0]);
    ARM7_SetThreadPriority(ARM7_GetWirelessDriverThread(), ARM7_WirelessSchedulingState.priorities[1]);
    ARM7_SetThreadPriority(&ARM7_WirelessServiceThreadA, ARM7_WirelessSchedulingState.priorities[2]);
    ARM7_UnlockThreadSwitch();
    ARM7_SetIRQInterruptState(state);
}
