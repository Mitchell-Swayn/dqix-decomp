#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void ClearWordAndTwoHalfwords_Main020727D8(void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020727EC; symbol: func_020727ec; size: 0xC.
extern "C" void ResetWordAndTwoHalfwordRecord(void* a){ClearWordAndTwoHalfwords_Main020727D8(a);}
