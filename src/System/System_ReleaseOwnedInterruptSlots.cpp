#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/main @ 0x211166c; symbol: data_0211166c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111670; symbol: data_02111670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned OSInitVramExclusive_UnknownRoleZeroInitializedStorage;extern "C" volatile unsigned short OSInitVramExclusive_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" int OsCountZeroBits(unsigned);
// Original: arm9/main @ 0x020C9A88; symbol: func_020c9a88; size: 0x88.
extern "C" void System_ReleaseOwnedInterruptSlots(unsigned mask,unsigned owner){unsigned pending;int irq=_Z20DisableIRQInterruptsv();pending=mask&OSInitVramExclusive_UnknownRoleZeroInitializedStorage&0x1ff;for(;;){int index=31-OsCountZeroBits(pending);if(index<0)break;unsigned clear=~(1u<<index);pending&=clear;if(owner==OSInitVramExclusive_UnknownRoleZeroInitializedStorage_Variant2[index]){unsigned enabled=OSInitVramExclusive_UnknownRoleZeroInitializedStorage;OSInitVramExclusive_UnknownRoleZeroInitializedStorage_Variant2[index]=0;OSInitVramExclusive_UnknownRoleZeroInitializedStorage=enabled&clear;}}_Z20SetIRQInterruptStatei(irq);}
