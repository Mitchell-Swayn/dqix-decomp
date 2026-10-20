#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void Resource_DispatchValueToAlternateOrEmbeddedResource(void*,void*,void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0205EBB4; symbol: func_0205ebb4; size: 0xC.
extern "C" void CutsceneResource_StopOrFadeSequence(void* a,void* b,void* c){Resource_DispatchValueToAlternateOrEmbeddedResource(a,b,c);}
