#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111654; symbol: data_02111654.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitVAlarm_UnknownRoleZeroInitializedStorage[];extern "C" void _Z25DisableSpecificInterruptsj(unsigned int);
// Original: arm9/main @ 0x020C9288; symbol: func_020c9288; size: 0x48.
extern "C" void OS_InitVAlarm() { if(*(unsigned short*)OSInitVAlarm_UnknownRoleZeroInitializedStorage)return;*(unsigned short*)OSInitVAlarm_UnknownRoleZeroInitializedStorage=1;*(unsigned int*)(OSInitVAlarm_UnknownRoleZeroInitializedStorage+12)=0;*(unsigned int*)(OSInitVAlarm_UnknownRoleZeroInitializedStorage+16)=0;_Z25DisableSpecificInterruptsj(4);*(unsigned int*)(OSInitVAlarm_UnknownRoleZeroInitializedStorage+8)=0;*(unsigned int*)(OSInitVAlarm_UnknownRoleZeroInitializedStorage+4)=0; }
