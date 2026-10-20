#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Wireless_InitializeSharedCommandBuffers(unsigned,unsigned,unsigned);extern "C" unsigned WMiCheckIdle_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D3DCC; symbol: func_020d3dcc; size: 0x2C.
extern "C" ARM int WirelessCommand_InitializeAndClearSharedHalfword16(unsigned a,unsigned b){int status=Wireless_InitializeSharedCommandBuffers(a,b,0xf00);if(status)return status;*(short*)(WMiCheckIdle_UnknownRoleZeroInitializedStorage[1]+0x16)=0;return status;}
