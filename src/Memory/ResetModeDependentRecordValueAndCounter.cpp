// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x20e7e10; symbol: data_020e7e10.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex fe00000000001f0074000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e7e1c; symbol: data_020e7e1c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000fd0006000000003000000e00ffffc0000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e87c0; symbol: data_020e87c0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000030002000400050006000700080009000a000b0012000c000d000e000f0010001100130001001400150016001700180019001a001b001c001d001e001f00 ...; full span in module reference.
// Observed span: 68 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111654; symbol: data_02111654.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* Actor_GetPlacementDescriptor(char*);extern "C" signed char TextLayoutGetAnimatedDirectionOffset_UnknownRoleInitializedBytes[];extern "C" signed char TextLayoutGetAnimatedDirectionOffset_UnknownRoleInitializedBytes_Variant2[];extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];extern "C" char OSInitVAlarm_UnknownRoleZeroInitializedStorage[];extern "C" short ScriptGetOrderedLookupId_UnknownRoleInitializedBytes[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x0201FBAC; symbol: func_0201fbac; size: 0x34.
extern "C" void ResetModeDependentRecordValueAndCounter(unsigned char* p){if(p[0]==1 || p[0]==4)p[1]=3;else if(p[0]==2)*(unsigned int*)(p+16)=0x43080000;*(short*)(p+4)=0;}
