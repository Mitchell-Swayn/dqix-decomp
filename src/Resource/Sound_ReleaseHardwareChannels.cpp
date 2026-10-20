#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[];extern "C" void SoundCommand_SubmitOpcodeTwentySeven(unsigned,int);
// Original: arm9/main @ 0x020BBE64; symbol: func_020bbe64; size: 0x30.
extern "C" void Sound_ReleaseHardwareChannels(unsigned mask){if(!mask)return;SoundCommand_SubmitOpcodeTwentySeven(mask,0);SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[2]&=~mask;}
