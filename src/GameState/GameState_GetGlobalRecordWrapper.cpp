#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void* GameState_GetSerializedProgressState();
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020965F8; symbol: func_020965f8; size: 0xC.
extern "C" void* GameState_GetGlobalRecordWrapper(){return GameState_GetSerializedProgressState();}
