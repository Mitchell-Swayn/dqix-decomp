#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f226c; symbol: data_020f226c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void _Z18AwaitDMACompletioni(int);extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" int GXInit_UnknownRoleInitializedBytes[2];
// Original: arm9/main @ 0x020C3A0C; symbol: func_020c3a0c; size: 0x40.
extern "C" int GX_SetDefaultDMA(int next){int old=GXInit_UnknownRoleInitializedBytes[1];if(old!=-1)_Z18AwaitDMACompletioni(old);int irq=_Z20DisableIRQInterruptsv();GXInit_UnknownRoleInitializedBytes[1]=next;_Z20SetIRQInterruptStatei(irq);return old;}
