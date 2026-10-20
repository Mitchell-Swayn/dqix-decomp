#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void Resource_DispatchValueToAlternateOrEmbeddedResource(void*,void*,void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0205EABC; symbol: func_0205eabc; size: 0xC.
extern "C" void Resource_StopOrFadeSequence(void* a,void* b,void* c){Resource_DispatchValueToAlternateOrEmbeddedResource(a,b,c);}
