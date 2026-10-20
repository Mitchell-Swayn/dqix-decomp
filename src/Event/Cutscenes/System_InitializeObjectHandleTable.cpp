#include <globaldefs.h>
ARM
extern "C" void Bgm_StopPlaybackAndResetController(int object);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int Main_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/ov001 @ 0x021637D4; symbol: func_ov001_021637d4; size: 0x18.
extern "C" int System_InitializeObjectHandleTable(void) { Bgm_StopPlaybackAndResetController((int)&Main_UnknownRoleZeroInitializedStorage_Variant2); return 1; }
