#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void InitializeRecordWithField20Enabled(void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020280F8; symbol: func_020280f8; size: 0xC.
extern "C" void ResetEmbeddedPairArrayOwner(void* a){InitializeRecordWithField20Enabled(a);}
