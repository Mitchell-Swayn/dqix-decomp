#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" int WMi_StartParentEx(unsigned,int);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020D5204; symbol: func_020d5204; size: 0x10.
extern "C" int DispatchRequestWithModeOne(unsigned a){return WMi_StartParentEx(a,1);}
