#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void Object_Clear40Bytes(void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0202EEA4; symbol: func_0202eea4; size: 0x10.
extern "C" void ResetInterpolationRecordAtOffset1BC(char* a){Object_Clear40Bytes(a+444);}
