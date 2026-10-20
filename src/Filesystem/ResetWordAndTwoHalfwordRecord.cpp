#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void MessageTextTable_Reset(void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020727EC; symbol: func_020727ec; size: 0xC.
extern "C" void ResetWordAndTwoHalfwordRecord(void* a){MessageTextTable_Reset(a);}
