#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void* RecordLookup_GetSecondWordOfFoundEntry(void*,void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020E0434; symbol: func_020e0434; size: 0xC.
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void* a,void* b){return RecordLookup_GetSecondWordOfFoundEntry(a,b);}
