#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void ResourceHandle_RestoreArchiveHeapState(void*,void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0205EB80; symbol: func_0205eb80; size: 0x10.
extern "C" void SoundSfx_RestoreCurrentHeapState(char* a){ResourceHandle_RestoreArchiveHeapState(a,*(void**)(a+192));}
