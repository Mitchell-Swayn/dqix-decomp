#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <System/Interrupts.h>
extern "C" SignedAllocatorList data_021103bc;
// Original: arm9/main @ 0x020BF418; symbol: func_020bf418; size: 0x40.
extern "C" ARM SignedAllocatorHeader* RemoveFirstGlobalAllocatorEntryUnderIRQProtection(){int state=DisableIRQInterrupts();SignedAllocatorHeader* p=data_021103bc.ElementAfter(0);if(p)data_021103bc.Remove(p);SetIRQInterruptState(state);return p;}
