#include <globaldefs.h>
#include <Memory/HPXEAllocator.h>
#include <System/Interrupts.h>
ARM
// Original data: arm9/ov031 @ 0x2290d3c; symbol: data_ov031_02290d3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" HPXEAllocator* MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage;
extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/ov031 @ 0x0223CF00; symbol: func_ov031_0223cf00; size: 0x4C.
// Allocates from the shared HPXE heap while interrupt mask1 is disabled; allocation failure halts.
extern "C" void* Memory_AllocateSharedHeapOrHalt(unsigned length,int alignmentAndDirection)
{
 void* result;
 unsigned mask=DisableSpecificInterrupts(1);
 result=MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage->Allocate(length,alignmentAndDirection);
 if(!result)DisableInterruptsAndHaltForever();
 EnableSpecificInterrupts(mask);
 return result;
}
