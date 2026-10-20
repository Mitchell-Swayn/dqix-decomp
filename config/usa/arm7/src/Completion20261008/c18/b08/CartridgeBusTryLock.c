#pragma dont_inline on
#include "CartridgeService.h"
extern int ARM7_DisableIRQInterrupts(void);
extern unsigned short ARM7_GetBusLockOwner(void*);
extern int ARM7_TryAcquireGBABus(unsigned short);
/* Retain IRQ state and distinguish ARM9 ownership from an ARM7 lock claim. */
// Original: arm7/wram @ 0x03807580; symbol: ARM7_TryProtectedCartridgeBus.
int ARM7_TryProtectedCartridgeBus(unsigned short owner,ProtectedBusState *saved)
{
 saved->interruptState=ARM7_DisableIRQInterrupts();
 saved->ownedByOtherProcessor=ARM7_GetBusLockOwner((void*)0x027fffe8)&0x80;
 if(saved->ownedByOtherProcessor || !ARM7_TryAcquireGBABus(owner))return 1;
 return 0;
}
