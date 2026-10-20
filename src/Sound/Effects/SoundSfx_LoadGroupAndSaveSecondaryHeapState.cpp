#include <globaldefs.h>
extern "C" void ResourceHandle_RestoreArchiveHeapState(void*,int);extern "C" void TestBoundedResourceValueAfterStateInitialization(void*,int);extern "C" int ResourceHandle_ReadValueIfPresent(void*);struct State{char pad[0xb8];int a;short b;short gap;int c;};
// Original: arm9/main @ 0x0205EAD0; symbol: func_0205ead0; size: 0x38.
extern "C" ARM void SoundSfx_LoadGroupAndSaveSecondaryHeapState(State* p,int value,short key){ResourceHandle_RestoreArchiveHeapState(p,p->a);TestBoundedResourceValueAfterStateInitialization(p,value);p->b=key;p->c=ResourceHandle_ReadValueIfPresent(p);}
