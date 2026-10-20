#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5b4; symbol: data_ov031_0224e5b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02212248; symbol: func_ov031_02212248; size: 0x2C.
extern "C" unsigned int System_IsGlobalStateHalfwordFourEqualSix(void) { void* p = *(void**)((char*)&WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage + 4); return p && *(unsigned short*)((char*)p + 4) == 6; }
