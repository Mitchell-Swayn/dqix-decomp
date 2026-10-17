#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void Object_ClearFortyByteRecord(void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0203FCD4; symbol: func_0203fcd4; size: 0xC.
extern "C" void ClearFortyByteRecordIndirect(void* a){Object_ClearFortyByteRecord(a);}
