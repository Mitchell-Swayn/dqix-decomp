#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
// Original data: arm9/main @ 0x2111668; symbol: data_02111668.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short SystemHandleResetHandshakeReply_UnknownRoleZeroInitializedStorage;extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x020C9890; symbol: func_020c9890; size: 0x34.
extern "C" ARM void System_HandleResetHandshakeReply(int ignored,unsigned message){unsigned short command=(message&0x7f00)>>8;if(command==0x10){SystemHandleResetHandshakeReply_UnknownRoleZeroInitializedStorage=1;return;}DisableInterruptsAndHaltForever();}
