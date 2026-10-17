#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020D0834; symbol: func_020d0834; size: 0xC.
extern "C" bool WaitForCardReadManagerIdle(){return AwaitCardReadManagerIdle();}
