#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void ResourceTimer_ClearTwoBuffersAndSubmit();
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020BBE10; symbol: func_020bbe10; size: 0xC.
extern "C" void ResourceManager_InvokeGlobalReset(){ResourceTimer_ClearTwoBuffersAndSubmit();}
