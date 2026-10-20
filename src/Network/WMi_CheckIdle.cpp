#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int WirelessCommand_ReadInitializedStatus();extern "C" unsigned char* WMiCheckIdle_UnknownRoleZeroInitializedStorage[];extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
// Original: arm9/main @ 0x020D4204; symbol: func_020d4204; size: 0x48.
extern "C" int WMi_CheckIdle(){int result=WirelessCommand_ReadInitializedStatus();if(result)return result;_Z24InvalidateDataCacheRangePKvj(*(void**)(WMiCheckIdle_UnknownRoleZeroInitializedStorage[1]+4),2);unsigned short value=**(unsigned short**)(WMiCheckIdle_UnknownRoleZeroInitializedStorage[1]+4);return value<=1?3:0;}
