#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x211214c; symbol: data_0211214c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short IPCHandleChannelThirteenCompletion_UnknownRoleZeroInitializedStorage;extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x020D18A4; symbol: func_020d18a4; size: 0x2C.
extern "C" ARM void IPC_HandleChannelThirteenCompletion(unsigned a,unsigned b){if((b&63)==1){IPCHandleChannelThirteenCompletion_UnknownRoleZeroInitializedStorage=1;return;}DisableInterruptsAndHaltForever();}
