#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020D0040; symbol: func_020d0040; size: 0x10.
extern "C" void LockCardReadManagerModeTwo(unsigned short a){LockCardReadManager(a,2);}
