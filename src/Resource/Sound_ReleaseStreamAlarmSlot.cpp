#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020BBEF8; symbol: func_020bbef8; size: 0x20.
 extern "C" void Sound_ReleaseStreamAlarmSlot(unsigned int bit) { SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[1]&=~(1U<<bit); }
