#include <globaldefs.h>
ARM
extern "C" void ClearWordAndTwoBytes(void*);extern "C" void InitializeEmbeddedResourcesAndClearBuffers(void*);
// Original: arm9/main @ 0x0203EF60; symbol: func_0203ef60; size: 0x1C.
extern "C" void* InitializeOwnerAndEmbeddedResourceState(void* p){ClearWordAndTwoBytes(p);InitializeEmbeddedResourcesAndClearBuffers(p);return p;}
