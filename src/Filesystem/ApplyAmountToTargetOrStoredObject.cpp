#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void DispatchValueToAlternateOrEmbeddedResource(void*,void*,void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0205EC20; symbol: func_0205ec20; size: 0xC.
extern "C" void ApplyAmountToTargetOrStoredObject(void* a,void* b,void* c){DispatchValueToAlternateOrEmbeddedResource(a,b,c);}
