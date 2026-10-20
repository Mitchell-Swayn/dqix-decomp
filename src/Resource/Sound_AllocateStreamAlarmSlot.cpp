#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{unsigned unknown;volatile unsigned flags;};extern "C" State SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BBEB0; symbol: func_020bbeb0; size: 0x48.
extern "C" int Sound_AllocateStreamAlarmSlot(){unsigned bit=1;int i=0;unsigned used=SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage.flags;do{if(!(used&bit)){SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage.flags|=bit;return i;}++i;bit<<=1;}while(i<8);return -1;}
