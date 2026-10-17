#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void DispatchValueToAlternateOrEmbeddedResource(void*,void*,void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0205EABC; symbol: func_0205eabc; size: 0xC.
extern "C" void ResourceHandle_SetGlobalOwnerAndApplyHandleValue_Main0205EABC(void* a,void* b,void* c){DispatchValueToAlternateOrEmbeddedResource(a,b,c);}
