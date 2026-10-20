#pragma dont_inline on
#include "CartridgeService.h"
extern int ARM7_ReleaseGBABus(unsigned short);
extern int ARM7_SetIRQInterruptState(int);
/* Release only the ARM7-acquired lock, then restore the saved interrupt mask. */
// Original: arm7/wram @ 0x038075D0; symbol: ARM7_ReleaseProtectedCartridgeBus.
void ARM7_ReleaseProtectedCartridgeBus(unsigned short owner,ProtectedBusState *saved)
{
 if(!saved->ownedByOtherProcessor)ARM7_ReleaseGBABus(owner);
 ARM7_SetIRQInterruptState(saved->interruptState);
}
