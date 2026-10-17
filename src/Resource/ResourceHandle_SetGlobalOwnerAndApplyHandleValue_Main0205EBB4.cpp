#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void DispatchValueToAlternateOrEmbeddedResource(void*,void*,void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0205EBB4; symbol: func_0205ebb4; size: 0xC.
extern "C" void ResourceHandle_SetGlobalOwnerAndApplyHandleValue_Main0205EBB4(void* a,void* b,void* c){DispatchValueToAlternateOrEmbeddedResource(a,b,c);}
